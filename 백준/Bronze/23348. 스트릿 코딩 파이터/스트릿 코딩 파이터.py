a, b, c = map(int, input().split())
res = 0
for _ in range(int(input())):
    temp = 0
    for _ in range(3):
        v = list(map(int, input().split()))
        temp += v[0] * a + v[1] * b + v[2] * c
    res = max(res, temp)

print(res)
