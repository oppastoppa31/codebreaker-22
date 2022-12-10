
# Task B2

For Task B2, the goal was to find the login URL of the attacker's site.

The first step for Task B2 was to figure out how the backend site worked. Using the URL from [Task B1](/taskB1/) (<https://svvkkrekekpuvfcl.ransommethis.net/>) and the [gitdumper.sh](gitdumper.sh) script I was able to dump the source code for the site. the file [server.py](app/server.py) contains the login URL on line 29.

![url.png](/images/url.png)

```
Answer: https://svvkkrekekpuvfcl.ransommethis.net/mdfhjooavqjkqbsn/
```
