import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():

    s = input().rstrip()

    ma = {"F": "Foundation", "C": "Claves", "V": "Veritas", "E": "Exploration"}

    print(ma[s[0]])


if __name__ == "__main__":
    solve()
