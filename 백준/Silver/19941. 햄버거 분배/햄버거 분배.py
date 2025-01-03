n, k = map(int, input().split())
v = list(input())
is_used = [False] * n

res = 0
for i in range(n):
    if v[i] == "H":
        continue

    flag = False
    for j in range(max(0, i - k), min(n, i + k + 1)):
        if v[j] == "H" and not is_used[j]:
            is_used[j] = True
            flag = True
            break

    if flag:
        res += 1

print(res)
