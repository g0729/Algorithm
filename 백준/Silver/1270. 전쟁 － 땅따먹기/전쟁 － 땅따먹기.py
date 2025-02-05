import sys
from collections import defaultdict

input = sys.stdin.readline
print = sys.stdout.write

for _ in range(int(input())):
    v = list(map(int, input().split()))

    dic = defaultdict(int)
    flag = False
    for i in range(1, len(v)):
        dic[v[i]] += 1
        if dic[v[i]] > v[0] // 2:
            print(str(v[i]) + "\n")
            flag = True
            break

    if not flag:
        print("SYJKGW\n")
