from itertools import product

n, k = map(int, input().split())
v = list(map(int, input().split()))
v = sorted(v)

for a in product(v, repeat=k):
    print(" ".join(list(map(str, a))))
