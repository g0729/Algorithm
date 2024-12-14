v = ["K", "O", "R", "E", "A"]
idx = 0
res = 0
for a in list(input()):
    if a == v[idx]:
        idx = (idx + 1) % 5
        res += 1

print(res)
