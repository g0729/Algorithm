n, s, r = map(int, input().split())
S = list(map(int, input().split()))
R = list(map(int, input().split()))

c = [a for a in S if a in R]

S = [a for a in S if a not in c]
R = [a for a in R if a not in c]

S.sort()
answer = 0
for a in S:
    if a - 1 in R:
        R.remove(a - 1)
    elif a + 1 in R:
        R.remove(a + 1)
    else:
        answer += 1


print(answer)
