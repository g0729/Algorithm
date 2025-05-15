MOD = 1234567

v = [[0 for _ in range(10)] for _ in range(1001)]
for i in range(10):
    v[1][i] = 1

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
for i in range(2, 1001):

    for j in range(1, 10):
        x, y = (j - 1) // 3, (j - 1) % 3

        for k in range(4):
            nx, ny = x + dx[k], y + dy[k]

            if nx < 0 or nx >= 3 or ny < 0 or ny >= 3:
                continue

            num = nx * 3 + ny + 1

            v[i][j] += v[i - 1][num]

    v[i][0] = v[i - 1][7]
    v[i][7] += v[i - 1][0]


for _ in range(int(input())):
    print(sum(v[int(input())]) % MOD)
