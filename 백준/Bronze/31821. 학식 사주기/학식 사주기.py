v = [int(input()) for _ in range(int(input()))]

res = sum(v[int(input()) - 1] for _ in range(int(input())))

print(res)
