import sys
from itertools import combinations

input = sys.stdin.readline


def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a_sum, b_sum = [], []

    for comb in combinations(a, k):
        a_sum.append(sum(comb))
    for comb in combinations(b, k):
        b_sum.append(sum(comb))

    a_sum.sort(), b_sum.sort()

    res = [int(1e9), -1]
    res[1] = max(abs(a_sum[0] - b_sum[-1]), abs(a_sum[-1] - b_sum[0]))

    a_idx, b_idx = 0, 0

    while a_idx < len(a_sum) and b_idx < len(b_sum):
        res[0] = min(res[0], abs(a_sum[a_idx] - b_sum[b_idx]))

        if a_sum[a_idx] < b_sum[b_idx]:
            a_idx += 1
        elif a_sum[a_idx] == b_sum[b_idx]:
            return res
        elif a_sum[a_idx] > b_sum[b_idx]:
            b_idx += 1

    return res


if __name__ == "__main__":

    for _ in range(int(input())):
        print(" ".join(map(str, solve())))
