n = int(input())
t = int(input())
v = list(map(int, input().split()))
idx = 1
for a in list(map(int, input().split())):
    now = idx + (a - 1)
    now = (now - 1) % (2 * n) + 1
    print(v[now - 1], end=" ")
    idx = now
