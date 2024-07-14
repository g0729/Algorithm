n = int(input())
v = list(input())
cnt = sum(map(lambda x: int(x) % 2, v))
if cnt == n - cnt:
    print(-1)
elif cnt > n - cnt:
    print(1)
else:
    print(0)
