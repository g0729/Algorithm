n, k, q, m = map(int, input().split())
sleep = set(list(map(int, input().split())))

attend = [1] * (n + 3)
attend[0] = attend[1] = attend[2] = 0
for a in list(map(int, input().split())):
    if a in sleep:
        continue
    idx = a
    while idx <= n + 2:
        attend[idx] = 0
        idx += a

acc_sum = [0] * (n + 3)

for a in sleep:
    attend[a] = 1
for i in range(1, len(acc_sum)):
    acc_sum[i] = acc_sum[i - 1] + attend[i]

for _ in range(m):
    s, e = map(int, input().split())
    print(acc_sum[e] - acc_sum[s - 1])
