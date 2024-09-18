x, y, w, s = map(int, input().split())

if 2 * w > s:
    if w > s:
        if (dis := abs(x - y)) % 2 == 0:
            print(min(x, y) * s + dis * s)
        else:
            print(min(x, y) * s + (dis - 1) * s + w)
    else:
        print(min(x, y) * s + abs(x - y) * w)
else:
    print((x + y) * w)
