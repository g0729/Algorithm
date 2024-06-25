from itertools import combinations
from collections import defaultdict

x = list(map(str, input().rstrip()))
y = list(map(str, input().rstrip()))
z = list(map(str, input().rstrip()))
k = int(input())

dic = defaultdict(int)


def cal(v):
    for a in combinations(v, k):
        dic["".join(a)] += 1


cal(x)
cal(y)
cal(z)

answer = [key for key, value in dic.items() if value >= 2]

print("\n".join(sorted(answer)) if answer else -1)
