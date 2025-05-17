import sys

input = sys.stdin.readline
print = sys.stdout.write

se = set()

for _ in range(int(input())):
    for a in list(input().split()):
        if a in se:
            print("1")
            exit(0)

        se.add(a)

print("0")
