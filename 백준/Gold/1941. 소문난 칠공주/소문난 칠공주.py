import sys
from itertools import combinations
from collections import deque

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def check(selected):
    visited = [False] * 7
    q = deque()
    q.append(selected[0])
    visited[0] = True

    while q:
        cur = q.popleft()
        x, y = cur // 5, cur % 5
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= 5 or ny < 0 or ny >= 5:
                continue

            point = nx * 5 + ny

            for j in range(7):
                if selected[j] == point and not visited[j]:
                    visited[j] = True
                    q.append(point)
                    break

    return all(visited)


def solve():
    MAP = [list(input().strip()) for _ in range(5)]
    res = 0
    for selected in combinations(range(25), 7):
        if sum([1 for i in selected if MAP[i // 5][i % 5] == "S"]) < 4:
            continue

        if check(selected):
            res += 1

    print(res)


if __name__ == "__main__":
    solve()
