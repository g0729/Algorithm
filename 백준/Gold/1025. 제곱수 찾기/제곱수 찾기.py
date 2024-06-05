from math import sqrt

n, m = map(int, input().split())
MAP = [list(input()) for _ in range(n)]
answer = -1

for x in range(n):
    for y in range(m):
        for dx in range(-n, n + 1):
            for dy in range(-m, m + 1):
                if dx == 0 and dy == 0:
                    continue
                v = [MAP[x][y]]
                nx = x + dx
                ny = y + dy
                while 0 <= nx < n and 0 <= ny < m:
                    v.append(MAP[nx][ny])
                    nx += dx
                    ny += dy
                for i in range(len(v)):
                    temp = int("".join(v[: i + 1]))

                    if sqrt(temp) == int(sqrt(temp)):
                        answer = max(answer, temp)

print(answer)
