n = int(input())

if n < 10:
    print(n)
    exit(0)

res = 9
for i in range(1, pow(10, len(str(n)) // 2)):
    temp = str(i) + str(i)[::-1]
    if int(temp) <= n:
        res += 1
    for j in range(10):
        temp = str(i) + str(j) + str(i)[::-1]
        if int(temp) <= n:
            res += 1

print(res)
