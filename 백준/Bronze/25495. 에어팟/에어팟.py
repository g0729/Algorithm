n = int(input())
v = list(map(int, input().split()))

now = 2
res = 2

for i in range(1, n):
    if now == 0:
        now = 2
    elif v[i] == v[i - 1]:
        now *= 2
    else:
        now = 2
    res += now

    if res >= 100:
        res = 0
        now = 0
print(res)
