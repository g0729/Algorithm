r, s = map(int, input().split())
MAP = [list(input()) for _ in range(r)]

dis = 3000
for i in range(s):
    top, down = -1, -1
    for j in range(r):
        if MAP[j][i] == "X":
            top = j
        elif MAP[j][i] == "#" and down == -1:
            down = j

    if top != -1:
        dis = min(dis, down - top - 1)

res = [["." for _ in range(s)] for _ in range(r)]

for i in range(r):
    for j in range(s):
        if MAP[i][j] == "X":
            res[i + dis][j] = "X"
        elif MAP[i][j] == "#":
            res[i][j] = "#"

for a in res:
    print("".join(a))
