from itertools import combinations


def dis(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


n, k = map(int, input().split())
v = [list(map(int, input().split())) for _ in range(n)]
answer = int(1e9)
for arr in combinations(range(n), k):
    temp = []
    for house in v:
        temp.append(min([dis(v[a], house) for a in arr]))
    answer = min(answer, max(temp))

print(answer)
