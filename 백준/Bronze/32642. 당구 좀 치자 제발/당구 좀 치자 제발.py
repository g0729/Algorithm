sum = 0
cur = 0
input()
v = list(map(int, input().split()))

for i in v:
    if i == 1:
        cur += 1
    else:
        cur -= 1
    sum += cur

print(sum)
