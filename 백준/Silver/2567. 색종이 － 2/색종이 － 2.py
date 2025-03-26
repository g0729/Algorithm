v = [[False] * 102 for _ in range(102)]

for _ in range(int(input())):
    a, b = map(int, input().split())

    for i in range(a, a + 10):
        for j in range(b, b + 10):
            v[i][j] = True


dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
res = 0
for i in range(1, 101):
    for j in range(1, 101):
        if not v[i][j]:
            continue

        for k in range(4):
            nx, ny = i + dx[k], j + dy[k]

            res += 1 if not v[nx][ny] else 0

print(res)
