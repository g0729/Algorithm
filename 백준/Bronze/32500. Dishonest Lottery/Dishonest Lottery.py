n = int(input())
v = [0] * 51
for _ in range(10 * n):
    for a in map(int, input().split()):
        v[a] += 1

flag = False
for i in range(len(v)):
    if v[i] > 2 * n:
        flag = True
        print(i, end=" ")

if not flag:
    print("-1")
