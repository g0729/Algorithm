import sys

input = sys.stdin.readline


def solve():
    n = int(input())

    if n % 3 == 0:
        print((n // 3) * 2)
        for i in range(1, n):
            if i % 3 == 0:
                continue
            print(i, end=" ")

        print("\n", n // 3, sep="")
        for i in range(1, (n // 3) + 1):
            print(i * 3, end=" ")
    elif n % 3 == 1:
        print((n // 3) * 2)
        for i in range(1, n):
            if i % 3 == 0:
                continue
            print(i, end=" ")

        print("\n", n // 3, sep="")
        for i in range(1, (n // 3) + 1):
            print(i * 3, end=" ")

    elif n % 3 == 2:
        print(n // 3 * 2 + 1)
        print(1, end=" ")

        for i in range(n // 3):
            print(i * 3 + 3, i * 3 + 4, end=" ")
        print()
        print(n // 3 + 1)
        print(2, end=" ")
        for i in range(n // 3):
            print(i * 3 + 5, end=" ")


if __name__ == "__main__":
    solve()
