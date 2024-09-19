n, m = map(int, input().split())
a = set(list(map(int, input().split())))
b = set(list(map(int, input().split())))
a = a - b

print(len(a))
for i in sorted(list(a)):
    print(i, end=" ")
