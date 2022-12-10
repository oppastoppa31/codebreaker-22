
# Task 6

For Task 6, the goal was to modify the authentication token to gain access to the attacker's backend site.

The first step for Task 6 was to figure out how the backend site worked. Using the token from [Task 5](/task5/data), I decoded the token using [CyberChef](https://gchq.github.io/CyberChef/#recipe=JWT_Decode()&input=ZXlKMGVYQWlPaUpLVjFRaUxDSmhiR2NpT2lKSVV6STFOaUo5LmV5SnBZWFFpT2pFMk5UTTVNRGsyT1Rrc0ltVjRjQ0k2TVRZMU5qVXdNVFk1T1N3aWMyVmpJam9pYkdoa1JIUkVjbTl5VmpNNWNYcHJlbFF5WVhSMGVWYzRhamxUVGxaWVR6Y2lMQ0oxYVdRaU9qSTBNRFEzZlEuREZoWVhtLVhwSU8xQWJsQnpqa3dNNzRJRThST1BtVnJ2a21yb2dhUUhJUQ) to obtain

![token.png](/images/token.png)

![expired.png](/images/expired.png)

The token would not be accepted because it was expired so I changed the expiration date to the near future. The HMAC key could be obtained from [util.py](/taskB2/app/util.py) (TZcaeOJi0T3YY0vbP1qxMLAzGQdGa3ku). After signing the token with this key, I was able to log in to the site.

![newtoken.png](/images/newtoken.png)

```
Answer: eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE2NTM5MDk2OTksImV4cCI6MTc2NjUwMTY5OSwic2VjIjoibGhkRHREcm9yVjM5cXprelQyYXR0eVc4ajlTTlZYTzciLCJ1aWQiOjI0MDQ3fQ.JukAJj92R6_vOv2Njh8oIJbGfK_2Sc0ymF_C2ldDXYc
```
