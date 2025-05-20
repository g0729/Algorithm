import sys

input = sys.stdin.readline
print = sys.stdout.write

n, m = map(int, input().split())
score = list(map(int, input().split()))
res = -1
idx = 0

for i in range(m):
    v = input().split()
    temp = 0
    for j in range(1, len(v)):
        temp += score[j - 1] if v[j] == "O" else 0

    if temp > res:
        res = temp
        idx = v[0]
    elif temp == res and int(idx) > int(v[0]):
        idx = v[0]

print(str(idx) + " " + str(res))
