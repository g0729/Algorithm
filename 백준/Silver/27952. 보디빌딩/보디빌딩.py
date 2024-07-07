n, x = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

weights = 0
for i in range(n):
    weights += b[i]
    if weights < a[i]:
        print(-1)
        exit(0)

answer = (weights - a[-1]) // x

print(answer)
