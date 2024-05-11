def solution(n):
    arr = [[0] * (i + 1) for i in range(n)]
    dx = [1, 0, -1]
    dy = [0, 1, -1]
    idx = 1
    x, y, dir = 0, 0, 0
    for _ in range(n * (n + 1) // 2):
        arr[x][y] = idx
        idx += 1
        nx, ny = x + dx[dir], y + dy[dir]
        if (ny > nx) or (nx < 0 or nx >= n or ny < 0 or ny >= n):
            dir = (dir + 1) % 3
        elif arr[nx][ny] != 0:
            dir = (dir + 1) % 3
        nx, ny = x + dx[dir], y + dy[dir]
        x, y = nx, ny

    answer = []
    for a in arr:
        answer += a
    return answer
