s = list(map(lambda x: 1 if x == "Y" else 0, input()))

res = 0
for i in range(len(s)):
    if s[i] == 1:
        for j in range(i, len(s), i + 1):
            s[j] = (s[j] + 1) % 2

        res += 1

print(res if sum(s) == 0 else -1)
