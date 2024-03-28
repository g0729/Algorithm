INF = 987654321
MOD = 1000000007
MAX = 100000

n = int(input())
u, d, l, r = -1e10, 1e10, 1e10, -1e10

for _ in range(n):
    a=list(input().split())
    
    if a[2] == 'L':
        if l > int(a[0]):
            l = int(a[0])
    if a[2] == 'U':
        if int(a[1]) > u:
            u = int(a[1])
    if a[2] == 'R':
        if r < int(a[0]):
            r = int(a[0])
    if a[2] == 'D':
        if d > int(a[1]):
            d = int(a[1])

if u == -1e10 or r == -1e10 or d == 1e10 or l == 1e10:
    print("Infinity")
else:
    print((d - u - 1) * (l - r - 1))
