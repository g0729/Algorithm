import sys
from itertools import combinations_with_replacement as comb


def check(v, target, k):
    return sum(target // a for a in v) >= k


def bin_search(v, k):

    lo, hi = 0, int(1e13)

    while lo + 1 < hi:
        mid = (lo + hi) >> 1

        if check(v, mid, k):
            hi = mid
        else:
            lo = mid

    return hi


def solve():
    n, k, c = map(int, input().split())
    v = list(map(int, input().split()))
    res = int(1e13)
    for i in range(c + 1):
        for cheers in comb(range(n), i):
            temp = v.copy()
            for idx in cheers:
                temp[idx] -= 1

            if any(temp[idx] < 1 for idx in cheers):
                continue

            res = min(res, bin_search(temp, k))

    print(res)


if __name__ == "__main__":
    solve()
