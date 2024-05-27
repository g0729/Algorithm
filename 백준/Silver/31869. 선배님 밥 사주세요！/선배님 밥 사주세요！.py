import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
dic = defaultdict(list)

for _ in range(n):
    name, a, b, c = input().split()
    dic[name] = [int(a), int(b), int(c)]

available = [False] * (100)

for _ in range(n):
    name, a = input().split()

    if dic[name][2] <= int(a):
        day = (dic[name][0] - 1) * 7 + dic[name][1]
        available[day] = True

answer = 0
contd = 0
for a in available:
    if a:
        contd += 1
        answer = max(answer, contd)
    else:
        contd = 0

print(answer)
