from itertools import permutations
from math import sqrt


def dis(p1, p2):
    return sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)


cur = tuple(map(int, input().split()))

v = [list(map(int, input().split())) for _ in range(3)]
res = 1e9
for a, b, c in permutations(range(3), 3):
    temp = dis(cur, v[a]) + dis(v[a], v[b]) + dis(v[b], v[c])
    res = min(res, temp)

print(int(res))
