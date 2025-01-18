n, x = map(int, input().split())
v = list(map(int, input().split()))
res = int(1e9)
for i in range(n - 1):
    res = min(res, v[i] + v[i + 1])

print(res * x)
