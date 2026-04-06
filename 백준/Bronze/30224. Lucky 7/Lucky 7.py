import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    s = input().rstrip()

    if not "7" in s:
        print("1" if int(s) % 7 == 0 else "0")
    else:
        print("3" if int(s) % 7 == 0 else "2")


if __name__ == "__main__":
    solve()
