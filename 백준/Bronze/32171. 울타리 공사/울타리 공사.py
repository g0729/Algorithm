p1, p2 = [], []
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())

    if not p1:
        p1, p2 = [a, b], [c, d]
    else:
        p1[0] = min(p1[0], a)
        p1[1] = min(p1[1], b)
        p2[0] = max(p2[0], c)
        p2[1] = max(p2[1], d)

    print((p2[0] - p1[0]) * 2 + (p2[1] - p1[1]) * 2)
