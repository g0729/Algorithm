import sys

input = sys.stdin.readline
print = sys.stdout.write


def check(target):
    sum = 0
    cnt = 0
    for a in v:
        if a[1] <= target:
            sum += a[0]
            cnt += 1

        if cnt == n:
            break
    return sum >= m if cnt == n else False


def bin_search():
    lo, hi = 0, int(1e12)

    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid
    return hi


n, m, k = map(int, input().split())
v = [tuple(map(int, input().split())) for _ in range(k)]
v = sorted(v, key=lambda x: -x[0])

if (res := bin_search()) != int(1e12):
    print(str(res))
else:
    print("-1")
