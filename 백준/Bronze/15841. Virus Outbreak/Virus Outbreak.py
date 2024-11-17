l = [0, 1] + [0] * 490
for i in range(2, 490):
    l[i] = l[i - 2] + l[i - 1]
while True:
    n = int(input())
    if n == -1:
        break
    print(f"Hour {n}: {l[n]} cow(s) affected")
