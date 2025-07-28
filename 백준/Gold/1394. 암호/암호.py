import sys

input = sys.stdin.readline


def solve():
    ma = {c: idx + 1 for idx, c in enumerate(list(input().strip()))}
    res = 0
    cur = 1
    for c in list(input().strip())[::-1]:
        res = (res + cur * ma[c]) % 900528
        cur = (cur * len(ma)) % 900528

    print(res % 900528)


if __name__ == "__main__":
    solve()
