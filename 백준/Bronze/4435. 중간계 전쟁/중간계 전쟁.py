for i in range(int(input())):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = a[0] + a[1] * 2 + (a[2] + a[3]) * 3 + a[4] * 4 + a[5] * 10
    d = b[0] + (b[1] + b[2] + b[3]) * 2 + b[4] * 3 + b[5] * 5 + b[6] * 10
    print(f"Battle {i+1}: ", end="")
    if c < d:
        print("Evil eradicates all trace of Good")
    elif c > d:
        print("Good triumphs over Evil")
    else:
        print("No victor on this battle field")
