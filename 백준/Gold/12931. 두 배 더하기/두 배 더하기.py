n = int(input())
v = list(map(int, input().split()))

res = 0
while True:
    for i in range(len(v)):
        res += v[i] % 2
        v[i] //= 2
    if sum(v) == 0:
        break
    res += 1
print(res)
