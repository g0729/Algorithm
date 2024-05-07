from collections import deque


def solution(maps):
    answer = 1
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    q = deque()
    q.append((0, 0))
    n, m = len(maps), len(maps[0])
    visited = [[False] * m for _ in range(n)]
    visited[0][0] = True
    while q:
        size = len(q)

        for _ in range(size):
            x, y = q.popleft()
            if [x, y] == [n - 1, m - 1]:
                return answer

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if 0 <= nx < n and 0 <= ny < m:
                    if not visited[nx][ny] and maps[nx][ny]:
                        visited[nx][ny] = True
                        q.append((nx, ny))
        answer += 1

    return -1
