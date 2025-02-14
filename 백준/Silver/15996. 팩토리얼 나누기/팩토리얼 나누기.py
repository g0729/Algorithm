n, a = map(int, input().split())
res = 0
cur = a
while n >= cur:
    res += n // cur
    cur *= a
print(res)
