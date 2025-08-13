import sys

input = sys.stdin.readline
C = [[0] * 100 for _ in range(100)]


def cal_comb():
    for i in range(100):
        C[i][0] = 1
        for j in range(1, i + 1):
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]


def check(v):
    for i in range(len(v) - 1):
        if v[i] > v[i + 1]:
            return False
    return True


def solve():
    n = int(input())
    v = list(map(int, list(str(n))))

    if not check(v):
        print("-1")
        return
    res = 0
    for i in range(1, len(v)):
        res += C[i + 8][i]

    last = 1
    for i in range(len(v)):
        rem_len = len(v) - i - 1
        for j in range(last, v[i]):
            res += C[(10 - j) + rem_len - 1][rem_len]
        last = v[i]
    print(res + 1)


if __name__ == "__main__":
    cal_comb()
    for _ in range(int(input())):
        solve()
