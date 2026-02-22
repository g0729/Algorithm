from collections import defaultdict

ma = defaultdict(int)

for _ in range(int(input())):
    s, a = input().split()
    ma[s] += int(a)

for k, v in ma.items():
    if v == 5:
        print("YES")
        exit(0)


print("NO")
