a, b = map(int, input().split())
invalid = [1, 3, 4]
res = ""
if a == b:
    res = "="
elif a in invalid and b in invalid:
    res = "="
elif a in invalid:
    res = "<"
elif b in invalid:
    res = ">"
else:
    if a == 0:
        if b == 2:
            res = ">"
        elif b == 5:
            res = "<"
    elif a == 2:
        if b == 0:
            res = "<"
        elif b == 5:
            res = ">"
    elif a == 5:
        if b == 0:
            res = ">"
        elif b == 2:
            res = "<"

print(res)
