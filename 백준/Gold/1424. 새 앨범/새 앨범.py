n = int(input())
l = int(input())
c = int(input())

can_store = (c + 1) // (l + 1)
if can_store % 13 == 0:
    can_store -= 1
answer = (n + can_store - 1) // can_store
left = n % can_store
if left > 0 and left % 13 == 0:
    if answer == 1:
        answer += 1
    elif can_store % 13 == 1 and left + 2 > can_store:
        answer += 1
print(answer)
