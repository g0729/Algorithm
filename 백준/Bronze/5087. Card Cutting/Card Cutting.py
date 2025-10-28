import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    while True:
        s = input().strip()
        if s == "#":
            break

        v = list(map(lambda x: 1 if x == "A" else int(x), s.split()[:-1]))

        odd = len([x for x in v if x % 2])
        print("Draw" if len(v) - odd == odd else ("Cheryl" if len(v) - odd < odd else "Tania"))


if __name__ == "__main__":
    solve()
