n, m = map(int, input().split())
v = [False] * (n + 1)
for a in map(int, input().split()):
    v[a] = True

last = 0
res = 0
for i in range(1, n + 1):
    if v[i]:
        continue

    if last == 0:
        res = 7
        last = i
    elif i - last <= 3:
        res += (i - last) * 2
        last = i
    else:
        res += 7
        last = i

print(res)
