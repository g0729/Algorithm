def lsb(num):
    s = bin(num)[2:]
    if len(s) >= 4:
        return s[-4:]
    return "0" * (4 - len(s)) + s


s = ""
for _ in range(3):
    a = int(input())
    s += lsb(a)
res = int(s, 2)

print("0" * (4 - len(str(res))) + str(res))
