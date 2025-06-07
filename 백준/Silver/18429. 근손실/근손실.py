from itertools import permutations

n, k = map(int, input().split())
v = list(map(int, input().split()))
res = 0
for order in permutations(range(n)):
    weight = 500
    flag = True
    for a in order:
        weight += v[a] - k

        if weight < 500:
            flag = False
            break

    res += 1 if flag else 0

print(res)
