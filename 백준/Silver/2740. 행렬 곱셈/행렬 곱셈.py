n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
m, k = map(int, input().split())
b = [list(map(int, input().split())) for _ in range(m)]

c = [[0] * k for _ in range(n)]

for i in range(n):
    for j in range(k):
        for p in range(m):
            c[i][j] += a[i][p] * b[p][j]

for r in c:
    print(*r)
