from collections import deque


def bfs():
    q = deque()
    q.append(start)
    visited[start[0]][start[1]] = True
    cnt = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    while q:
        x, y = q[0]
        q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if visited[nx][ny]:
                continue
            if MAP[nx][ny] == "X":
                continue

            q.append((nx, ny))
            visited[nx][ny] = True

            if MAP[nx][ny] == "P":
                cnt += 1

    return cnt


n, m = map(int, input().split())
MAP = [list(input()) for _ in range(n)]
visited = [[False] * m for _ in range(n)]
start = (0, 0)
for i in range(n):
    for j in range(m):
        if MAP[i][j] == "I":
            start = (i, j)

answer = bfs()

print(answer if answer != 0 else "TT")
