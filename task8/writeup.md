
# Task 8

For Task 8, the goal was to find the key used to encrypt database entries in the keyMaster.db.

The necessary files for this challenge, as well as [Task 9](/task9/)  were obtained through a path escape in the log retrieval function.

- keygeneration.log
- keyMaster
- keyMaster.db
- user.db
- victims.db

![pathescape.png](/images/pathescape.png)

Through analyzing the keyMaster binary in IDA Pro, it appeared that there was an AES Encryption function encrypting entries in the keyMaster database.

![CBCEncrypter.png](/images/CBCEncrypter.png)

After finding the address of the instantiation of the AES-CBC-Encrypter and placing a breakpoint on it in GDB, I was able to recover the AES encryption key. The following script should provide the key.

```bash
echo -n '
b *0x5B8844
r
set $a = *(unsigned long long *)$rbx
dump mem aes.key $a $a+32
q' > script.gdb
gdb ./keyMaster < script.gdb
xxd -p  task8/aes.key | tr -d '\n' | base64
```

```
Answer: MzQ2NWM0YzRiZDY5MTBhMzJiMTU0NjQzZmI2MDQwZWZhMDRkYzVkNWYzMjQzMTFlNWU4MWY0YTgx
NWFiOTVlMg==
```
