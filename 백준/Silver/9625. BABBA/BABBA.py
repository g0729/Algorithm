k = int(input())
a, b = 1, 0
for _ in range(k):
    na, nb = b, a + b
    a, b = na, nb

print(a, b)
