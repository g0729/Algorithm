n, k = map(int, input().split())

sum = 0
res = 0
for _ in range(n):
    a, b = map(int, input().split())
    sum += a - b
    res = max(res, sum - k)

print(res)
