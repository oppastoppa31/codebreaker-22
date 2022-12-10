
# Task 7

For Task 7, the goal was to find the login for an admin user and generate a valid token.

Using the token obtained from [Task 6](/task6/) and the source code obtained from [Task B2](/taskB2/), an SQL Injection is discovered in the ```userinfo``` function of [server.py](/taskB2/app/server.py).

![userinfo.png](/images/userinfo.png)

The only problem with this is that the values returned from the SQL query need to be valid integers. This is where unicode charcodes come in handy! [getsecret.py](getsecret.py) outputs the UID and the secret of an admin user through this SQL injection with the help of the SQL ```unicode() and SUBSTR()``` functions. The retrieved UID and secret were
```foynvhtWtFjgu36YsIOuKc6N1CdoesAc and 42936``` for the user ```SteadfastParallelogram```.

```
Answer: eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE2NjgyMjg5NTcsImV4cCI6MTY3MDgyMDk1Nywic2VjIjoiZm95bnZodFd0RmpndTM2WXNJT3VLYzZOMUNkb2VzQWMiLCJ1aWQiOjQyOTM2fQ.fCpNqiWX9bZzhzBViSXtb11yfxLe6e7s6O7NG986Mtw
```
