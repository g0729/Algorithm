import re

a = re.compile("(100+1+|01)+")

for _ in range(int(input())):
    s = input()
    if a.fullmatch(s) == None:
        print("NO")
    else:
        print("YES")
