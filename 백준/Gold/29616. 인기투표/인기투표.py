import sys

input = sys.stdin.readline


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def solve():
    n, p = map(int, input().split())
    v1 = list(map(int, input().split()))
    gcd1 = v1[0]

    for i in range(1, len(v1)):
        gcd1 = gcd(gcd1, v1[i])

    v1 = list(map(lambda x: x // gcd1, v1))

    print(sum(v1), end=" ")

    v2 = list(map(int, input().split()))

    gcd2 = v2[0]

    for i in range(1, len(v2)):
        gcd2 = gcd(gcd2, v2[i])

    v2 = list(map(lambda x: x // gcd2, v2))

    min_multiply = 0
    for i in range(len(v2)):
        try:
            min_multiply = max(min_multiply, (v1[i] + v2[i] - 1) // v2[i])
        except:
            continue

    print(sum(v2) * min_multiply)


if __name__ == "__main__":
    solve()
