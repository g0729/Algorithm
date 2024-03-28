n = int(input())

s = list(input())

for i in range(n//2):
    if s[i] == '?':
        s[i] = s[n-i-1]
    elif s[n-i-1] == '?':
        s[n-i-1] = s[i]
for i in range(n):
    if s[i]=='?':
        s[i]='a'
print("".join(s))
