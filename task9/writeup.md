
# Task 9

For Task 9, the goal was to decrypt one of the victims files using a key recovered from reverse analysis of [Task 8](/task8/).

Through analyzing the keyMaster binary in IDA Pro, I learned that the keys were based on a timestamp and the MAC address of the attacker's PC. After analyzing [ransom.sh](/taskA2/tools/ransom.sh) I found out the encryption algorithm used was AES-128-CBC.

```bash
#!/bin/sh
read -p "Enter encryption key: " key
hexkey=`echo -n $key | ./busybox xxd -p | ./busybox head -c 32`
export hexkey
./busybox find $1 -regex '.*\.\(pdf\|doc\|docx\|xls\|xlsx\|ppt\|pptx\)' -print -exec sh -c 'iv=`./openssl rand -hex 16`; echo -n $iv > $0.enc; ./openssl enc -e -aes-128-cbc -K $hexkey -iv $iv -in $0 >> $0.enc; rm $0' \{\} \; 2>/dev/null
```

The IV retrieved from the file was ```0x2ee3e9eabd47b321499f421c94f0901f```. In [keygeneration.log](keygeneration.log) the timestamp was 1651492526 (2022-05-02T07:55:26-04:00) for the given victim. The values in the key generation log and in the actual UUID vary by a few seconds so a large range is iterated over to verify that no keys are missed. This corresponds with a UUID in the range of roughly ```b0000000-ca0e-11``` to ```d0000000-ca0e-11```. In [decrypt.cpp](decrypt.cpp) this range is iterated over and the PDF magic bytes are searched for. The decryption key was ```be1e0245-ca0e-11```.

![important_data.png](/images/important_data.png)

```
Answer: TZ296WCmDwdQyMJmtaac5zY1cfId4qPy
```
