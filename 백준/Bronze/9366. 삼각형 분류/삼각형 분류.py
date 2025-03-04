for t in range(int(input())):
    a, b, c = map(int, input().split())

    print(f"Case #{t+1}: ", end="")
    if max(a, b, c) >= (sum([a, b, c]) - max(a, b, c)):
        print("invalid!")
    elif a == b and b == c:
        print("equilateral")
    elif a == b or b == c or a == c:
        print("isosceles")
    else:
        print("scalene")
