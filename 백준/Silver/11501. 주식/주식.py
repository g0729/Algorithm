for _ in range(int(input())):
    n = int(input())
    res = 0
    max = 0
    v = list(map(int, input().split()))

    for i in range(len(v) - 1, -1, -1):
        if v[i] > max:
            max = v[i]
        else:
            res += max - v[i]
    print(res)
