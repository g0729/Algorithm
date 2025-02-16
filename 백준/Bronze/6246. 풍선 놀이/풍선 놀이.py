n, q = map(int, input().split())
v = [False] * (n + 1)

for _ in range(q):
    a, b = map(int, input().split())

    while a <= n:
        v[a] = True
        a += b
res = 0

for i in range(1, n + 1):
    if not v[i]:
        res += 1
print(res)
