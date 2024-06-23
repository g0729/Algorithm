n, m, k = map(int, input().split())
cnt = [0] * (n)
v = [list(map(int, input().split())) for _ in range(n)]

for idx in range(m):
    for person in range(n):
        cnt[person] += v[person][idx]
        if cnt[person] >= k:
            print(person + 1, idx + 1)
            exit(0)
