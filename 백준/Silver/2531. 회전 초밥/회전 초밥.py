n, d, k, c = map(int, input().split())
v = [int(input()) for _ in range(n)]
v = v + v[:k]
cnt = [0] * (d + 1)
kinds = 1
cnt[c] = 1
for i in range(k):
    if cnt[v[i]] == 0:
        kinds += 1
    cnt[v[i]] += 1
answer = kinds

for i in range(k, len(v)):
    if cnt[v[i]] == 0:
        kinds += 1
    cnt[v[i]] += 1
    if cnt[v[i - k]] == 1:
        kinds -= 1
    cnt[v[i - k]] -= 1
    answer = max(answer, kinds)
print(answer)
