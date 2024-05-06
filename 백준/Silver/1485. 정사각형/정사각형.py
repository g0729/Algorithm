from math import sqrt
from collections import Counter


def distance(dot1, dot2):
    return sqrt((dot1[0] - dot2[0]) ** 2 + (dot1[1] - dot2[1]) ** 2)


for _ in range(int(input())):
    points = [list(map(int, input().split())) for _ in range(4)]
    dist = []
    for i in range(3):
        for j in range(i + 1, 4):
            dist.append(distance(points[i], points[j]))
    c = Counter(dist)
    if len(c) != 2:
        print("0")
    elif c.most_common(1)[0][1] != 4:
        print("0")
    else:
        print("1")
