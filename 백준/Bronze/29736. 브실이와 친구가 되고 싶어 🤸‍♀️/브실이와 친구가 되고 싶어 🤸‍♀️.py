a, b = map(int, input().split())
c, d = map(int, input().split())

left, right = c - d, c + d
left = max(left, a)
right = min(right, b)

if (res := right - left + 1) <= 0:
    print("IMPOSSIBLE")
else:
    print(res)
