from math import comb


def f(n, l, i):

    if n == 0:
        return
    pivot = 0

    for k in range(l + 1):
        pivot += comb(n - 1, k)

    if i <= pivot:
        s[N - n] = "0"
        f(n - 1, l, i)

    else:
        s[len(s) - n] = "1"
        f(n - 1, l - 1, i - pivot)


N, L, I = map(int, input().split())
s = ["0"] * N

f(N, L, I)

print("".join(s))
