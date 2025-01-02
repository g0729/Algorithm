for _ in range(int(input())):
    odd, even = 0, 0
    _ = input()
    for a in list(map(int, input().split())):
        if a % 2 == 1:
            odd += 1
        else:
            even += 1

    if odd == even or max(odd, even) % 2 == 0:
        print("heeda0528")
    else:
        print("amsminn")
