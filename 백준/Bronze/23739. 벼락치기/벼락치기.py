res = 0
left = 30
for _ in range(int(input())):
    n = int(input())

    if n <= left:
        res += 1
        left -= n
    else:
        if left * 2 >= n:
            res += 1
        left = 0

    if left == 0:
        left = 30

print(res)
