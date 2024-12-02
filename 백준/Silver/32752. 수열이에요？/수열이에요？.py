n, l, r = map(int, input().split())
v = list(map(int, input().split()))
v = v[: l - 1] + sorted(v[l - 1 : r]) + v[r:]

for i in range(1, len(v)):
    if v[i] < v[i - 1]:
        print("0")
        exit(0)

print("1")
