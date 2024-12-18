n = int(input())
se = set(int(input()) for _ in range(n))

res = 5
for a in se:
    temp = 4
    for i in range(a + 1, a + 5):
        if i in se:
            temp -= 1
    res = min(res, temp)

print(res)
