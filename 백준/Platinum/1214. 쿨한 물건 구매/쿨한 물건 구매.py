d, p, q = map(int, input().split())

if p < q:
    p, q = q, p

res = int(1e10)

for i in range(0, min(d // p, q) + 1):
    t = d - p * i
    temp = (t // q) * q

    if temp < t:
        temp += q

    res = min(res, temp + p * i)

temp = (d // p) * p
if temp < d:
    temp += p
res = min(res, temp)
print(res)
