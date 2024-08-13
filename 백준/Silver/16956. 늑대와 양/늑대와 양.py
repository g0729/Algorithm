r, c = map(int, input().split())
MAP = [list(input()) for _ in range(r)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for i in range(r):
    for j in range(c):
        if MAP[i][j] == "S":
            for k in range(4):
                x = i + dx[k]
                y = j + dy[k]
                if x < 0 or x >= r or y < 0 or y >= c:
                    continue
                if MAP[x][y] == "W":
                    print(0)
                    exit(0)
        if MAP[i][j] == ".":
            MAP[i][j] = "D"
print(1)
for i in range(r):
    print("".join(MAP[i]))
