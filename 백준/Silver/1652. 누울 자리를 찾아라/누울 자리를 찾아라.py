n = int(input())
v = [list(input()) for _ in range(n)]

res_x, res_y = 0, 0
for i in range(n):
    cnt = 0

    for j in range(n):
        if v[i][j] == ".":
            cnt += 1
        elif v[i][j] == "X":
            if cnt >= 2:
                res_x += 1
            cnt = 0

    if cnt >= 2:
        res_x += 1

for i in range(n):
    cnt = 0

    for j in range(n):
        if v[j][i] == ".":
            cnt += 1
        elif v[j][i] == "X":
            if cnt >= 2:
                res_y += 1
            cnt = 0

    if cnt >= 2:
        res_y += 1

print(res_x, res_y)
