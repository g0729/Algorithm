for _ in range(int(input())):
    n = int(input())

    answer = n * (n + 1) * (n + 2)
    answer //= 6
    print(answer * answer)
