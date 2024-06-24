s = input()
answer = 0
for _ in range(int(input())):
    a = input()
    if a[:5] == s[:5]:
        answer += 1

print(answer)
