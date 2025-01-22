fac = [1, 1]
for i in range(1, 30):
    fac.append(fac[i] + fac[i - 1])

d, k = map(int, input().split())

for i in range(1, k):
    if (k - fac[d - 3] * i) % fac[d - 2] == 0 and k > fac[d - 3] * i:
        print(i, (k - fac[d - 3] * i) // fac[d - 2], sep="\n")
        exit(0)
