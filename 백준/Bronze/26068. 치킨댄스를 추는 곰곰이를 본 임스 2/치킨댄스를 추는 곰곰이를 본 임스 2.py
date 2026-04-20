res = 0
for _ in range(int(input())):
    s = input()

    if int(s.split("-")[1]) <= 90:
        res += 1

print(res)
