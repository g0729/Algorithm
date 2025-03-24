from itertools import combinations
from functools import reduce

n = int(input())

v = list(map(int, input().split()))
res = 0
for comb in combinations(range(1, n), 3):
    temp = (
        reduce(lambda acc, cur: acc * cur, v[0 : comb[0]], 1)
        + reduce(lambda acc, cur: acc * cur, v[comb[0] : comb[1]], 1)
        + reduce(lambda acc, cur: acc * cur, v[comb[1] : comb[2]], 1)
        + reduce(lambda acc, cur: acc * cur, v[comb[2] :], 1)
    )
    res = max(res, temp)
print(res)
