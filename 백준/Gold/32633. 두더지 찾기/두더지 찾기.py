import sys

input = sys.stdin.readline


def gcd(a, b):
    while b:
        a %= b
        a, b = b, a

    return a


def lcm(a, b):
    return a * b // gcd(a, b)


def solve():
    n, l = map(int, input().split())
    v = list(map(int, input().split()))
    b = list(map(int, input().split()))

    candidate = 1

    for i in range(len(b)):
        if b[i] == 1:
            candidate = lcm(candidate, v[i])

            if candidate > l:
                return -1

    if candidate > l:
        return -1

    for i in range(len(b)):
        if b[i] == 0 and candidate % v[i] == 0:
            return -1

    return candidate


if __name__ == "__main__":
    print(solve())
