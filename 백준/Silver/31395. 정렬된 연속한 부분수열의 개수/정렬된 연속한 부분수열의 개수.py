n = int(input())
v = list(map(int, input().split()))
res = 1
cur = 1
for i in range(1, n):
    if v[i] > v[i - 1]:
        cur += 1
    else:
        cur = 1
    res += cur

print(res)
