from itertools import permutations
from functools import reduce
from bisect import bisect_right

v = []
for i in range(1, 10):
    for j in permutations(range(1, 10), i):
        s = reduce(lambda acc, cur: acc + str(cur), j, "")
        v.append(int(s))

v.sort()
while True:
    try:
        idx = bisect_right(v, int(input()))
        if idx == len(v):
            print("0")
        else:
            print(v[idx])
    except EOFError:
        break
