import math


def hanoi(n, From, temp, to, cnt):
    if n == 1:
        print(From, to)
        return
    else:
        num = pow(2, n - 1) - 1
        if cnt <= num:
            hanoi(n - 1, From, to, temp, cnt)
        elif cnt == num + 1:
            print(From, to)
            return
        else:
            hanoi(n - 1, temp, From, to, cnt - num - 1)


n, k = map(int, input().split())
hanoi(n, 1, 2, 3, k)
