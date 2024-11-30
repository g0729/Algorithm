n, m = map(int, input().split())
v = list(map(int, input().split()))
sum = 0
for i in range(len(v) - 1, -1, -1):
    sum += v[i]

    if sum >= m:
        print(i + 1)
        exit()

print("-1")
