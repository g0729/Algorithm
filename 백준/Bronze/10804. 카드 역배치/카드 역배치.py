v = [i for i in range(1, 21)]
for _ in range(10):
    a, b = map(int, input().split())
    v[a - 1 : b] = v[a - 1 : b][::-1]

print(" ".join(map(str, v)))
