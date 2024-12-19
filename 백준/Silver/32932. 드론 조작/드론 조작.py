n, k = map(int, input().split())
se = set(tuple(map(int, input().split())) for _ in range(n))
cur = (0, 0)
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
dir = {"U": 0, "D": 1, "R": 2, "L": 3}

for op in list(input()):
    op = dir[op]

    nx, ny = cur[0] + dx[op], cur[1] + dy[op]

    if (nx, ny) in se:
        continue

    cur = (nx, ny)

print(*cur)
