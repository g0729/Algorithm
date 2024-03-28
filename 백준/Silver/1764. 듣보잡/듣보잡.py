se = set()

res = []
n, m = map(int, input().split())

for _ in range(n):
    se.add(input())

for _ in range(m):
    s = input()
    if s in se:
        res.append(s)

res.sort()
print(len(res))
for i in res:
    print(i)
