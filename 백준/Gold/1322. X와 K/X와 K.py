import sys

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())

    n, k = bin(n)[2:][::-1], bin(k)[2:][::-1]

    res = ""
    idx = 0
    for bit in n:
        if bit == "1":
            res += "0"
        else:
            res += k[idx]
            idx += 1

            if idx >= len(k):
                break

    if idx <= len(k):
        res += k[idx:]

    print(int(res[::-1], 2))


if __name__ == "__main__":
    solve()
