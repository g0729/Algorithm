v = [0, 1, 2, 2]

for i in range(4, 1001):
    temp = 1

    if i % 2:
        for j in range(1, i, 2):
            temp += v[(i - j) // 2]
    else:
        for j in range(2, i, 2):
            temp += v[(i - j) // 2]
        temp += v[i // 2]

    v.append(temp)

for _ in range(int(input())):
    print(v[int(input())])
