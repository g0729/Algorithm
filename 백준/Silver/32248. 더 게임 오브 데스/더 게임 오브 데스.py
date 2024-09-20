from collections import deque


def bfs():
    global t
    now = 1
    visited = [False] * (n + 1)
    visited[1] = True

    while True:
        now = v[now]
        t -= 1
        if t == 0:
            print(now)
            return
        if visited[now]:
            break
        visited[now] = True

    cycle = [now]
    init = now
    now = v[now]
    while now != init:
        cycle.append(now)
        now = v[now]

    print(cycle[t % len(cycle)])


n, t = map(int, input().split())
v = [0] + list(map(int, input().split()))


bfs()
