v = [0, 1, 2]
MAX = 10**100

for i in range(2, int(100000)):
    v.append(v[i] + v[i - 1])
    if v[-1] > MAX:
        break


while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    res = 0
    for i in range(1, len(v)):
        if a <= v[i] <= b:
            res += 1
        if v[i] > b:
            break

    print(res)
