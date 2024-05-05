n = int(input())
answer = -1
for _ in range(n):
    a, b = map(int, input().split())
    if a <= b:
        answer = b if answer == -1 else min(answer, b)

print(answer)
