import sys

input = sys.stdin.readline


def solve():
    while True:
        s = input().strip()
        if s == "0":
            break
        length = len(s)
        res = 0

        while True:
            if s == s[::-1]:
                print(res)
                break

            s = str(int(s) + 1).zfill(length)
            res += 1


if __name__ == "__main__":
    solve()
