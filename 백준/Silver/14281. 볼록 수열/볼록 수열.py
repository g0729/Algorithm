n = int(input())
v = list(map(int, input().split()))
res = 0
flag = True
while flag:
    flag = False
    for i in range(1, n - 1):
        if v[i - 1] + v[i + 1] < 2 * v[i]:
            flag = True
            res += v[i] - (v[i - 1] + v[i + 1]) // 2
            v[i] = (v[i - 1] + v[i + 1]) // 2
print(res)
