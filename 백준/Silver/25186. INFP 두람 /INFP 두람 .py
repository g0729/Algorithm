n = int(input())
v = list(map(int, input().split()))

if sum(v) == 1:
    print("Happy")
    exit(0)
if max(v) > sum(v) // 2:
    print("Unhappy")
else:
    print("Happy")
