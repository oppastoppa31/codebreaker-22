#include <bitset>
#include <filesystem>
#include <fstream>
#include <indicators/block_progress_bar.hpp>
#include <iostream>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termcolor.h>

#define min 0xB0000000ULL /*beginning of keyspace*/
#define max 0xC0000000ULL /*end of keyspace*/
#define mod 0x100000 /*status update frequency*/
char key[] = "xxxxxxxx-ca0e-11\0"; /*keybase*/


using namespace std;
using namespace termcolor;
using namespace indicators;
BlockProgressBar bar{
    option::BarWidth{80}, option::Start{"["}, option::End{"]"},
    option::ForegroundColor{Color::green}};

// Null terminated buffer for strings
#define sbuf(buf, length) \
	buf	    = (unsigned char *)malloc(length + 1); \
	buf[length] = '\0';

// Convert ASCII string to hex string
string asciiToHex(string bin) {
	stringstream ss;
	for (unsigned char c : bin) {
		if (c == '\x00') break;
		unsigned int v = ((unsigned int)c & 0xFF);
		ss << uppercase << setfill('0') << setw(2) << hex << v;
	}
	return ss.str();
}
// convert an integer to a hex string
char *intToHex(int i) {
	stringstream ss;
	ss << setfill('0') << setw(8) << hex << i;
	char *result = (char *)malloc(9);
	ss >> result;
	return result;
}

int main(int argc, const char **argv) {
	unsigned char *iv =
	    (unsigned char *)"\x2e\xe3\xe9\xea\xbd\x47\xb3\x21\x49\x9f\x42\x1c"
			     "\x94\xf0\x90\x1f";  // IV retrieved from file
	vector<string> found;  // Decrypted results
	vector<string> keys;  // Possible keys
	ifstream file;	// PDF File
	file.open("important_data.pdf.enc");
	unsigned char *ciphertext;
	sbuf(ciphertext, 32);
	file.read((char *)ciphertext, 32);  // Read two blocks
	file.close();
	string plaintext;
	size_t ciphertext_len = 32;
	unsigned char *buf;  // Temporary decryption buffer
	sbuf(buf, 16);
	int buflen	    = 16;
	EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
	EVP_CIPHER_CTX_set_padding(ctx, 0);  // No padding
	for (unsigned long long prefix = min; prefix <= max; prefix++) {
		const char *h = intToHex(prefix);
		memcpy(&key, h, 8);  // Hex + keybase
		// Update status
		if (prefix % mod == 0) {
			auto percentage =
			    (prefix - min) * (100.0 / (max - min));
			string message = "; key: " + string(key) +
			    "; remaining/total: " + to_string(prefix - min) +
			    "/" + to_string(max - min) +
			    "; possibilities: " + to_string(keys.size());
			bar.set_option(option::PostfixText{message});
			bar.set_progress(percentage);
		}
		// Init cipher
		if (EVP_DecryptInit_ex(
			ctx, EVP_aes_128_cbc(), NULL,
			(const unsigned char *)&key, iv) != 1)
			ERR_print_errors_fp(stderr);
		// Decrypt 2 blocks
		for (unsigned int i = 0; i < ciphertext_len; i += 16) {
			if (EVP_DecryptUpdate(
				ctx, buf, &buflen, ciphertext, 16) != 1)
				ERR_print_errors_fp(stderr);
			plaintext.append((char *)buf);
		}
		if (EVP_DecryptFinal_ex(ctx, buf, &buflen) != 1)
			ERR_print_errors_fp(stderr);
		if (buflen != 0) plaintext += *buf;
		// Check for magic bytes
		if (plaintext.find("%PDF") != string::npos ||
		    plaintext.find("message") != string::npos ||
		    plaintext.find("important") != string::npos) {
			found.push_back(plaintext);
			keys.push_back(key);
		}
		plaintext = "";
	}
	// Cleanup
	EVP_CIPHER_CTX_free(ctx);
	free(ciphertext);
	free(buf);
	// Print key possibilities along with first 2 decrypted blocks
	cout << endl;
	for (int i = 0; i < keys.size(); i++)
		cout << "{key:\"" << keys[i] << "\",data:\"" << found[i]
		     << "\"}" << endl;
	if (keys.size() == 0) cout << "No keys :(" << endl;
	return 0 ? keys.size() > 0 : -1;
}