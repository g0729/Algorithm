n, l = map(int, input().split())
v = [tuple(map(int, input().split())) for _ in range(n)]
v.sort(key=lambda x: (x[0]))
res = 0

pos = v[0][0]

for start, end in v:
    if pos >= end + 1:
        continue
    if start > pos:
        pos = start

    length = end - pos
    needs = (length + l - 1) // l
    res += needs
    pos = pos + needs * l

print(res)
