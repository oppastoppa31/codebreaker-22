
# Task A2

For Task A2, the goal was to analyze the provided pcap to find the username of the attacker.

After extracting the root.tar.bz2, a certificate, presumably used in the TLS communication, [.cert.pem](root/.cert.pem) was found. After opening [session.pcap](session.pcap) in Wireshark and decrypting the TLS traffic with the key, I extracted [tools.dec.tar](tools.dec.tar) from the pcap. After removing the first few bytes so the tar magic was at the right offset, i ran the command ```tar tvf taskA2/tools.dec.tar``` to extract the username EliteOvalBench.

```
Answer: EliteOvalBench
```
