import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():
    n = int(input())
    ma = {"B": 0, "S": 1, "G": 2, "P": 3, "D": 4}
    v = [0] + list(map(int, input().split()))
    s = list(input().rstrip())

    total_spent, cur_spent, prev_spent = 0, 0, 0

    for c in s:
        grade = ma[c]

        if grade == 4:
            cur_spent = v[grade]
        else:
            cur_spent = v[grade + 1] - 1 - prev_spent

        total_spent += cur_spent
        prev_spent = cur_spent

    print(total_spent)


if __name__ == "__main__":
    solve()
