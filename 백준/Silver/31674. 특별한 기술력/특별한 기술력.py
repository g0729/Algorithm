MOD = 1000000007
n = int(input())
v = list(map(int, input().split()))
v.sort(reverse=True)

sum = v[0]

for i in range(1, n):
    temp = sum + v[i]
    sum = (sum + temp) % MOD

print(sum)
