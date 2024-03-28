for _ in range(int(input())):
    A, n = map(int, input().split())
    s = ''
    while A >= n:
        s = str(hex(A%n)[2:]) + s
        A //= n
    s = str(hex(A)[2:]) + s
    print(int(s == s[::-1]))