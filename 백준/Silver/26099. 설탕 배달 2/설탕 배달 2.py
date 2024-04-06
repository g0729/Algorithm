n = int(input())

if n == 1 or n == 2 or n == 4 or n == 7:
    print("-1")
else:
    mod = n % 5
    if mod == 0:
        print(n // 5)
    elif mod == 1:
        print(n // 5 + 1)
    elif mod == 2:
        print(n // 5 + 2)
    elif mod == 3:
        print(n // 5 + 1)
    else:
        print(n // 5 + 2)
