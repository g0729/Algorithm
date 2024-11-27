se = set()
for i in range(1, 10):
    se.add(i)

for i in range(2, 10):
    for j in range(1, 10):
        se.add(i * j)

if int(input()) in se:
    print("1")
else:
    print("0")
