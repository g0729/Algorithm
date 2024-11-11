cnt_a = [0] * 11
cnt_b = [0] * 11
sum_a, sum_b = 0, 0

for a in map(int, input().split()):
    cnt_a[a] += 1
    sum_a += a
for a in map(int, input().split()):
    cnt_b[a] += 1
    sum_b += a

if sum_a > sum_b:
    print("Algosia")
elif sum_a < sum_b:
    print("Bajtek")
else:
    for i in range(10, -1, -1):
        if cnt_a[i] > cnt_b[i]:
            print("Algosia")
            exit(0)
        elif cnt_a[i] < cnt_b[i]:
            print("Bajtek")
            exit(0)
    print("remis")
