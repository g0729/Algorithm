import sys

input = sys.stdin.readline


def solve():
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    print("Hanyang Univ." if a + c < b + d else ("Yongdap" if a + c > b + d else "Either"))


if __name__ == "__main__":
    solve()
