n, m = map(int, input().split())
v = list(map(int, input().split()))


def check(target):
    res = sum(map(lambda x: target // x, v))
    return res >= m


def bin_search():
    left, right = 0, max(v) * m

    while left + 1 < right:
        mid = (left + right) // 2

        if check(mid):
            right = mid
        else:
            left = mid

    return right


print(bin_search())
