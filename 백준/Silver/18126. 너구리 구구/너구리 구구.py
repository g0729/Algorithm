from collections import deque


def bfs():
    dist = [0] * (n + 1)
    visited = [False] * (n + 1)
    visited[1] = True
    q = deque()
    q.append(1)

    while q:
        now = q.popleft()

        for next, cost in edges[now]:
            if visited[next]:
                continue
            dist[next] = dist[now] + cost
            visited[next] = True
            q.append(next)

    return max(dist)


n = int(input())
edges = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    edges[a].append((b, c))
    edges[b].append((a, c))

print(bfs())
