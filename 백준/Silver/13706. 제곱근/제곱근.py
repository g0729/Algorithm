n = int(input())
lo, hi = 0, n

while lo + 1 < hi:
    mid = (lo + hi) // 2

    if mid * mid >= n:
        hi = mid
    else:
        lo = mid
print(hi)
