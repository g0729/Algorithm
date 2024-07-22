def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


n = int(input())
v = []

for _ in range(n):
    a, b = map(int, input().split())
    c = gcd(a, b)
    v.append((a // c, b // c))
deno = v[0][1]

for i in range(1, n):
    deno = (deno * v[i][1]) // gcd(deno, v[i][1])

nume = v[0][0] * (deno // v[0][1])

for i in range(1, n):
    nume = gcd(nume, v[i][0] * (deno // v[i][1]))

temp = gcd(deno, nume)
print(nume // temp, deno // temp)
