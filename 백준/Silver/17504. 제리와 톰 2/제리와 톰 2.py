def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


n = int(input())
v = list(map(int, input().split()))
den, num = v[-1], 1

for i in range(n - 2, -1, -1):
    num += den * v[i]
    den, num = num, den

num = den - num
temp = gcd(num, den)
num, den = num // temp, den // temp

print(num, den)
