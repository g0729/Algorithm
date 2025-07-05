from collections import deque

l = int(input(), 2)
r = int(input(), 2)

q = deque()
q.append(l)
res = 0
visited = [False] * 5000
visited[l] = True
while q:
    size = len(q)

    for _ in range(size):
        now = q.popleft()

        if now == r:
            print(res)
            exit(0)

        for i in range(len(bin(now)[2:]) - 1):
            temp = now ^ (1 << i)

            if temp < 5000 and not visited[temp]:
                q.append(temp)
                visited[temp] = True

        if now + 1 < 5000 and not visited[now + 1]:
            visited[now + 1] = True
            q.append(now + 1)

        if now != 0 and not visited[now - 1]:
            visited[now - 1] = True
            q.append(now - 1)

    res += 1
