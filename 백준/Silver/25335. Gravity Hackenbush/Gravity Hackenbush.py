import sys

input = sys.stdin.readline

n, m = map(int, input().split())
red, blue, green = 0, 0, 0
for _ in range(n):
    input()

for _ in range(m):
    _, _, color = input().split()

    if color == "R":
        red += 1
    elif color == "B":
        blue += 1
    else:
        green += 1


red += (green + 1) // 2
blue += green // 2

if red > blue:
    print("jhnah917")
else:
    print("jhnan917")
