black_dot = []
white_dot = []


def cal(list):

    temp = 0
    for i in range(len(list)):
        if i == 0:
            temp += list[i + 1] - list[i]
        elif i == len(list) - 1:
            temp += list[i] - list[i - 1]
        else:
            temp += min([list[i] - list[i - 1], list[i + 1] - list[i]])

    return temp


n = int(input())
dot_list = [[] for _ in range(n + 1)]
for _ in range(n):
    a, b = map(int, input().split())
    dot_list[b].append(a)

for i in range(1, n + 1):
    dot_list[i].sort()

res = 0

for i in range(1, n + 1):
    res += cal(dot_list[i])

print(res)
