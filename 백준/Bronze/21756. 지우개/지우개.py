n = int(input())
v = [i for i in range(1, n + 1)]

while len(v) != 1:
    v = v[1::2]

print(v[0])
