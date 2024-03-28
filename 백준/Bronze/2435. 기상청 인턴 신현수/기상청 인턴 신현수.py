n, k = map(int, input().split())
lis = list(map(int, input().split()))

res = int(-1e9)

for i in range(n - k + 1):
    res = max(res, sum(lis[i : i + k]))

print(res)
