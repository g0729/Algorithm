def check(target):
    total = 1
    cur = 0
    for i in range(len(v)):
        if target < v[i]:
            return False
        if cur + v[i] > target:
            total += 1
            cur = v[i]
        else:
            cur = cur + v[i]

    return total <= m


def bin_search():
    lo, hi = 0, int(1e9)

    while lo + 1 < hi:
        mid = (lo + hi) // 2

        if check(mid):
            hi = mid
        else:
            lo = mid
    return hi


n, m = map(int, input().split())
v = list(map(int, input().split()))

print(bin_search())
