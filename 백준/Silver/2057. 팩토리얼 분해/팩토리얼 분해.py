from math import factorial
from itertools import combinations


se = set()
facts = [factorial(i) for i in range(21)]

for i in range(1, 21):
    for j in combinations(range(21), i):
        sum_val = sum(facts[k] for k in j)
        se.add(sum_val)

print("YES" if int(input()) in se else "NO")
