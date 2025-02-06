n, m = map(int, input().split())
v = list(map(int, input().split()))

cnt = 0
for _ in range(n - 1):
    arr = list(map(int, input().split()))
    diff = 0
    for i in range(m):
        diff += abs(v[i] - arr[i])
    if diff > 2000:
        cnt += 1

print("YES" if cnt >= n // 2 else "NO")
