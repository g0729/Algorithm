t, x = map(int, input().split())
for _ in range(int(input())):
    flag = False
    _ = input()
    for a in list(map(int, input().split())):
        if a == x:
            flag = True

    if not flag:
        print("NO")
        exit(0)


print("YES")
