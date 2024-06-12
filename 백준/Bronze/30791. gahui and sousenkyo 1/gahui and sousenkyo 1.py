v = list(map(int, input().split()))
answer = sum(1 for i in range(1, 5) if v[0] - v[i] <= 1000)
print(answer)
