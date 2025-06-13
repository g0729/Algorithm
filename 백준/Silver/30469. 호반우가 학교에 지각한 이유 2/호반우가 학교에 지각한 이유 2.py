a, b, n = map(int, input().split())

if not str(b).startswith(("1", "3", "7", "9")):
    print("-1")
    exit(0)

if str(a).endswith(("1", "3", "7")):
    print(str(a) + "1" * (n - 4) + str(b))
else:
    print(str(a) + "7" + "1" * (n - 5) + str(b))
