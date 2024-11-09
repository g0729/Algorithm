a, b, c = map(int, input().split())

for i in range(1, a // b + 1):
    if (a - b * i) % c == 0 and (a - b * i) != 0:
        print("1")
        exit(0)

print("0")
