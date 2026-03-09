res = 0

for _ in range(int(input())):
    s = input().rstrip()
    res += 1 if s.startswith("C") else 0

print(res)
