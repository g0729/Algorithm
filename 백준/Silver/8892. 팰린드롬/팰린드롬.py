def check(s):
    return s == s[::-1]


for _ in range(int(input())):
    n = int(input())
    v = [input() for _ in range(n)]
    flag = False
    for i in range(len(v) - 1):
        for j in range(i + 1, len(v)):
            temp = v[i] + v[j]
            if check(temp):
                print(temp)
                flag = True
                break
            if flag:
                break
            temp = v[j] + v[i]
            if check(temp):
                print(temp)
                flag = True
                break
        if flag:
            break
    if not flag:
        print("0")
