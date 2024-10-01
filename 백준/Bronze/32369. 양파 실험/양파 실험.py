n, a, b = map(int, input().split())
onion = [1, 1]
binan = 1

for _ in range(n):
    onion[0] += a if binan == 1 else b
    onion[1] += a if binan == 0 else b

    if onion[binan] > onion[binan ^ 1]:
        binan ^= 1
    if onion[0] == onion[1]:
        onion[binan] -= 1

print(*sorted(onion, reverse=True))
