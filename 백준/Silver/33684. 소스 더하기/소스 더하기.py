n, k = map(int, input().split())
v = list(map(int, input().split()))
val = min(v)
res = 0
cnt = 0

if max(v) > k:
    print("0")
    exit(0)

if val <= 0:
    print("-1")
    exit(0)

for a in v:
    if a == val:
        if cnt == 0:
            cnt += 1
        else:
            res += (k - a) // val
    else:
        res += (k - a) // val

print(res + 1)
