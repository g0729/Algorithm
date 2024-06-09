n = int(input())
v = list(map(int, input().split()))
t, p = map(int, input().split())

print(sum((a - 1) // t + 1 for a in v))
print(n // p, n % p)
