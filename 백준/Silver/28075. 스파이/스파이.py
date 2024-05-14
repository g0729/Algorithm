def dfs(now, before, sum):
    if now == n:
        if sum >= m:
            global answer
            answer += 1
        return

    for i in range(6):
        next_value = arr[i] // 2 if i % 3 == before % 3 and now != 0 else arr[i]
        dfs(now + 1, i, sum + next_value)


n, m = map(int, input().split())
arr = list(map(int, input().split())) + list(map(int, input().split()))
answer = 0
dfs(0, 0, 0)
print(answer)
