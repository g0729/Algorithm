v = [tuple(map(int, input().split())) for _ in range(int(input()))]

for i in range(1, len(v)):
    if v[i][0] < v[i - 1][0] or v[i][1] < v[i - 1][1]:
        print("no")
        exit(0)

print("yes")
