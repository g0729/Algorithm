n = int(input())
s = input()
MOD = 1000000007
res = 0
fac = [1, 1, 2]

for i in range(3, n + 1):
    fac.append((fac[i - 1] * i) % MOD)

for i in range(n - 1):
    if s[i] == "<":
        continue
    sum = 1
    flag = False
    for j in range(i + 1, n):
        sum += 1 if s[j] == ">" else -1

        if s[j] == "<":
            flag = True
        if s[j] == ">" and flag:
            break
        if sum < 0:
            break
        if sum == 0:
            a = i
            b = n - j - 1

            res = (res + fac[a + b] * (pow((fac[a] * fac[b]) % MOD, MOD - 2, MOD))) % MOD
            flag = False
            break

print(res)
