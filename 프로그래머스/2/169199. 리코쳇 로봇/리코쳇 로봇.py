from collections import deque

def solution(board):
    n, m = len(board), len(board[0])

    startX, startY = 0, 0

    for i in range(n):
        flag = False
        for j in range(m):
            if board[i][j] == "R":
                startX, startY = i, j
                flag = True
                break
            if flag:
                break

    def bfs():
        q = deque()
        q.append([startX, startY])
        visited = [[False for _ in range(m)] for _ in range(n)]
        visited[startX][startY] = True
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        level = 0
        while q:
            size = len(q)

            for _ in range(size):
                x, y = q.popleft()

                if board[x][y] == "G":
                    return level
                for i in range(4):
                    nx, ny = x, y

                    while (0 <= nx < n and 0 <= ny < m) and board[nx][ny] != "D":
                        nx, ny = nx + dx[i], ny + dy[i]
                    nx, ny = nx - dx[i], ny - dy[i]

                    if not visited[nx][ny]:
                        visited[nx][ny] = True
                        q.append([nx, ny])
            level += 1
        return -1

    return bfs()

