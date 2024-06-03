import sys

input = sys.stdin.readline

answer = []

for _ in range(int(input())):
    v = list(input().split())
    if v[1] == "jaehak" and v[2] == "notyet" and (int(v[3]) > 3 or int(v[3]) == -1):
        answer.append((v[0], int(v[4])))

answer.sort(key=lambda x: x[1])
res = [a[0] for a in answer[:10]]
res.sort()
print(len(res))
print("\n".join(res))
