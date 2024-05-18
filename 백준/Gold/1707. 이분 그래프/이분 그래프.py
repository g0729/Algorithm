from collections import deque


def bfs(start):
    q = deque()
    q.append(start)

    while q:
        now = q.popleft()
        ncolor = color[now] % 2 + 1

        for next in edges[now]:
            if color[next] == 0:
                color[next] = ncolor
                q.append(next)
            elif color[now] == color[next]:
                return False

    return True


for _ in range(int(input())):
    v, e = map(int, input().split())
    color = [0] * (v + 1)
    edges = [[] for _ in range(v + 1)]
    flag = False
    for _ in range(e):
        a, b = map(int, input().split())
        edges[a].append(b)
        edges[b].append(a)

    for i in range(1, v + 1):
        if color[i]:
            continue

        color[i] = 1

        if not bfs(i):
            print("NO")
            flag = True
            break
    if not flag:
        print("YES")
