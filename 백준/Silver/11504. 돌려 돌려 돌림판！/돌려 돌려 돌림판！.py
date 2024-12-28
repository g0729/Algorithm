for _ in range(int(input())):
    n, m = map(int, input().split())

    x = int("".join(input().split()))
    y = int("".join(input().split()))

    v = list(input().split())
    v = v + v

    res = 0

    for i in range(n):
        num = int("".join(v[i : i + m]))

        if x <= num <= y:
            res += 1

    print(res)
