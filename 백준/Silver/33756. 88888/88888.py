MAX = 1000000000000000000
v = [8]
while v[-1] < MAX:
    v.append(v[-1] * 10 + 8)

v.reverse()

for _ in range(int(input())):
    n = int(input())

    cnt, idx = 0, 0
    while n != 0 and cnt <= 8:

        if v[idx] <= n:
            n -= v[idx]
            cnt += 1
        if v[idx] > n:
            idx += 1
        if n == 0:
            break

    print("Yes" if cnt <= 8 else "No")
