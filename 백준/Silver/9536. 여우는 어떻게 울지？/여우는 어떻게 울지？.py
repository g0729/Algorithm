import sys

for _ in range(int(input())):
    s=list(map(str,sys.stdin.readline().split()))

    while 1:
        temp=list(map(str,sys.stdin.readline().split()))

        if temp[0]=="what":
            break
        while temp[2] in s:
            s.remove(temp[2])

    print(" ".join(s))