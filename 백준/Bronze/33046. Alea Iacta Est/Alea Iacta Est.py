now = sum(map(int, input().split())) % 4
if now == 0:
    now = 4
temp = sum(map(int, input().split()))
now = (now + temp - 1) % 4
if now == 0:
    now = 4
print(now)
