import sys
from collections import deque

input = sys.stdin.readline


def bfs(MAP, visited, p):
    q = deque()
    q.append(p)
    visited[p[0]][p[1]] = True

    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]

    res = 0
    while q:
        cur = q.popleft()
        res += 1
        for i in range(4):
            nx, ny = cur[0] + dx[i], cur[1] + dy[i]

            if nx < 0 or nx >= 3 or ny < 0 or ny >= 3:
                continue

            if visited[nx][ny]:
                continue

            if MAP[nx][ny] == "O":
                q.append((nx, ny))
                visited[nx][ny] = True

    return res


def solve():
    MAP = [list(input().strip()) for _ in range(3)]
    v = list(map(int, input().split()))[1:]
    visited = [[False] * 3 for _ in range(3)]
    res = []

    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                continue

            if not visited[i][j] and MAP[i][j] == "O":
                res.append(bfs(MAP, visited, (i, j)))

    if sorted(res) == v:
        print("1")
    else:
        print("0")


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
