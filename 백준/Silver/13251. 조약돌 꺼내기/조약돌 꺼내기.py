import math

m = int(input())
v = list(map(int, input().split()))
k = int(input())
n = sum(v)

b = math.comb(n, k)
a = 0
for num in v:
    a += math.comb(num, k)

print(a / b)
