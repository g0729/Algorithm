import sys

input = sys.stdin.readline


def solve():
    dic = {"A": 1, "a": 1, "B": 2, "b": 1, "D": 1, "d": 1, "e": 1, "g": 1, "O": 1, "o": 1, "P": 1, "p": 1, "Q": 1, "q": 1, "R": 1, "@": 1}
    res = 0
    for c in input().strip():
        if c in dic:
            res += dic[c]

    print(res)


if __name__ == "__main__":
    solve()
