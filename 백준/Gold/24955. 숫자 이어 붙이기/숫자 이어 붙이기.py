from collections import deque


def bfs(start, end):
    q = deque()
    visited = [False] * (n + 1)
    visited[start] = True
    q.append((start, v[start]))

    while q:
        now = q.popleft()

        if now[0] == end:
            return now[1]

        for next_node in edges[now[0]]:
            if visited[next_node]:
                continue
            next_val = int(str(now[1]) + v[next_node]) % MOD
            visited[next_node] = True
            q.append((next_node, next_val))


n, q = map(int, input().split())
v = [0] + list(map(str, input().split()))
MOD = 1000000007

edges = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

for _ in range(q):
    a, b = map(int, input().split())
    print(bfs(a, b))
