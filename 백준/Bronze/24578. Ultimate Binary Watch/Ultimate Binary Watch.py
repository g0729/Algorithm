res = [["." for _ in range(4)] for _ in range(4)]
time = input()


for i in range(len(time)):
    temp = int(time[i])
    for j in range(4):
        if temp & 1 == 1:
            res[3 - j][i] = "*"
        temp >>= 1
for i in range(4):
    print(res[i][0], res[i][1], " ", res[i][2], res[i][3])
