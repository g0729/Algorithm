from math import comb

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(comb(m, n))
