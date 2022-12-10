
# Task 5

For Task 5, the goal was to extract an RSA key from a core dump, and decrypt a file using the extracted key.

***Note:** For this challenge, I would highly recommend installing a Ubuntu 20.04 chroot with the OpenSSL and OpenSSH debug symbols. The necessary packages can be installed with*

`````bash
echo "deb http://ddebs.ubuntu.com focal main restricted universe multiverse
deb http://ddebs.ubuntu.com focal-updates main restricted universe multiverse
deb http://ddebs.ubuntu.com focal-proposed main restricted universe multiverse" | sudo tee -a /etc/apt/sources.list.d/ddebs.list
&& apt install openssh-client-dbgsym=1:8.2p1-4ubuntu0.5 openssh-client=1:8.2p1-4ubuntu0.5 gdb nano sudo libcrypto1.1 ubuntu-dbgsym-keyring
`````

After analyzing the [SSH-Agent Source Code](https://raw.githubusercontent.com/openssh/openssh-portable/master/ssh-agent.c), I found that the keys were going to be stored in an encrypted format, making this task significantly more difficult. The wonderful writeup [here](https://security.humanativaspa.it/openssh-ssh-agent-shielded-private-key-extraction-x86_64-linux/) provides insight into decrypting the ssh keys once located. With the debug symbols installed, the script

`````cpp
dump mem shield_prekey idtab.idlist.tqh_first.key.shield_prekey idtab.idlist.tqh_first.key.shield_prekey+16384
dump mem shielded_private idtab.idlist.tqh_first.key.shielded_private idtab.idlist.tqh_first.key.shielded_private+1392
`````

will dump the needed information to decrypt the key. To decrypt the key run

`````bash
echo -n '
b main
b sshkey_free
r
set $key = (struct sshkey *)sshkey_new(0)
set $shielded_private = (unsigned char *)malloc(1392)
set $shield_prekey = (unsigned char *)malloc(16384)
set $fd = fopen("shielded_private", "r")
call fread($shielded_private, 1, 1392, $fd)
call fclose($fd)
set $fd = fopen("shield_prekey", "r")
call fread($shield_prekey, 1, 16384, $fd)
call fclose($fd)
set $key->shielded_private=$shielded_private
set $key->shield_prekey=$shield_prekey
set $key->shielded_len=1392
set $key->shield_prekey_len=16384
call sshkey_unshield_private($key)
bt
f 1
x *kp
call sshkey_save_private(*kp, "privatekey.pem", "", "comment", 0, "\x00", 0)
k
q' > script.gdb
gdb ssh-keygen < script.gdb
ssh-keygen -p -N "" -m pem -f privatekey.pem
`````

To decrypt the file run
```bash openssl pkeyutl -decrypt -inkey privatekey.pem -in data.enc```.

```
Answer: eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpYXQiOjE2NTM5MDk2OTksImV4cCI6MTY1NjUwMTY5OSwic2VjIjoibGhkRHREcm9yVjM5cXprelQyYXR0eVc4ajlTTlZYTzciLCJ1aWQiOjI0MDQ3fQ.DFhYXm-XpIO1AblBzjkwM74IE8ROPmVrvkmrogaQHIQ
```
