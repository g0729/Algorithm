while True:
    n = float(input())
    if n == 0:
        break
    res = 1 + n + n**2 + n**3 + n**4
    print("{:.2f}".format(res))
