import sys

input = sys.stdin.readline


def solve():
    available = [False] * 7
    available[1] = True
    n_available = [False] * 7

    for _ in range(int(input())):
        op1, v1, op2, v2 = input().split()
        v1, v2 = int(v1), int(v2)
        for i in range(7):
            n_available[i] = False

        for i in range(7):
            if available[i]:

                if op1 == "+":
                    n_available[(i + v1) % 7] = True
                else:
                    n_available[(i * v1 % 7)] = True
                if op2 == "+":
                    n_available[(i + v2) % 7] = True
                else:
                    n_available[i * v2 % 7] = True
        for i in range(7):
            available[i] = n_available[i]

    print("LUCKY" if available[0] else "UNLUCKY")


if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
