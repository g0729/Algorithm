n = int(input())

print("YES")
if n == 3:
    print("3 1 2")
elif n == 4:
    print("1 2 4 3")
elif n % 2:
    print("3 1 2", end=" ")
    for idx, n in enumerate(range(4, n + 1, 2)):
        if idx % 2 == 0:
            print(n, n + 1, end=" ")
        else:
            print(n + 1, n, end=" ")
else:
    for idx, n in enumerate(range(1, n + 1, 2)):
        if idx % 2 == 0:
            print(n, n + 1, end=" ")
        else:
            print(n + 1, n, end=" ")
