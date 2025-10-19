import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    a, b = [], []
    for _ in range(int(input())):
        s = input().strip()
        if s.startswith("boj.kr/"):
            a.append(s)
        else:
            b.append(s)

    a.sort(key=lambda x: int(x.split("/")[-1])), b.sort(key=lambda x: (len(x), x))

    for s in b:
        print(s)
    for s in a:
        print(s)


if __name__ == "__main__":
    solve()
