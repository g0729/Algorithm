def check(tar):
    sum = 0

    for i in range(len(v) - 1):
        diff = v[i + 1] - v[i]
        if diff > tar:
            sum += tar * (tar + 1) / 2
        else:
            sum += diff * tar - diff * (diff - 1) // 2

    sum += tar * (tar + 1) // 2

    return sum >= k


def binSearch():
    lo = 0
    hi = int(1e18)

    while lo + 1 < hi:
        mid = (lo + hi) // 2

        if check(mid):
            hi = mid
        else:
            lo = mid

    return hi


n, k = map(int, input().split())
v = list(map(int, input().split()))

print(binSearch())
