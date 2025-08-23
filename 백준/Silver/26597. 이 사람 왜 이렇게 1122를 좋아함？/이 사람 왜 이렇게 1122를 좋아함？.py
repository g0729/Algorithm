import sys

input = sys.stdin.readline


def solve():
    low, hi = -(10**18), 10**18
    answer_turn, paradox_turn = 0, 0
    for i in range(int(input())):
        num, op = input().split()
        num = int(num)

        if op == "^":
            low = max(low, num + 1)
        elif op == "v":
            hi = min(hi, num - 1)

        if low > hi:
            if paradox_turn == 0:
                paradox_turn = i + 1
        if low == hi:
            if answer_turn == 0:
                answer_turn = i + 1

    if paradox_turn > 0:
        print(f"Paradox!\n{paradox_turn}")
    elif answer_turn > 0:
        print(f"I got it!\n{answer_turn}")
    else:
        print("Hmm...")


if __name__ == "__main__":
    solve()
