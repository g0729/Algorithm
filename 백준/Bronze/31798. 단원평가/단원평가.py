from math import sqrt

a, b, c = map(int, input().split())

if a == 0 or b == 0:
    print(c**2 - (a + b))
elif c == 0:
    print(int(sqrt(a + b)))
