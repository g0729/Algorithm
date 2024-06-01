n, m = input().split()
if len(n) == len(m):
    print("1")
else:
    answer = 1 + int(m[: -len(n)])

    if n > m[-len(n) :]:
        answer -= 1

    print(answer)
