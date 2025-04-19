from collections import Counter

dic = Counter()
n = int(input())
for a in input().split():
    dic[a] = 0

for _ in range(n):
    for a in input().split():
        dic[a] += 1

v = sorted(list(dic.items()), key=lambda x: (-x[1], x[0]))

print("\n".join(" ".join(map(str, a)) for a in v))
