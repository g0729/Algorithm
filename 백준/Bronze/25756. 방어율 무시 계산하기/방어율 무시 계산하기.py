n = int(input())
now = 0.0
v = list(map(int, input().split()))

for i in range(n):
    now = 1 - (1 - now) * (1 - v[i] * 0.01)
    print(now * 100)
