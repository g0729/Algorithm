import sys

input = sys.stdin.readline
n = int(input().strip())

for i in range(n):
    if i == 0:
        print("*" * n + " " * (2 * n - 3) + "*" * n)
    elif i == n - 1:
        print(" " * i + "*" + " " * (n - 2) + "*" + " " * (n - 2) + "*")
    else:
        mid_spaces = 2 * (n - 1 - i) - 1
        print(" " * i + "*" + " " * (n - 2) + "*" + " " * mid_spaces + "*" + " " * (n - 2) + "*")

for i in range(n - 2, -1, -1):
    if i == 0:
        print("*" * n + " " * (2 * n - 3) + "*" * n)
    else:
        mid_spaces = 2 * (n - 1 - i) - 1
        print(" " * i + "*" + " " * (n - 2) + "*" + " " * mid_spaces + "*" + " " * (n - 2) + "*")
