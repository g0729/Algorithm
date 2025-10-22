import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve(lambda_nm):
    if 620 <= lambda_nm <= 780:
        return "Red"
    elif 590 <= lambda_nm < 620:
        return "Orange"
    elif 570 <= lambda_nm < 590:
        return "Yellow"
    elif 495 <= lambda_nm < 570:
        return "Green"
    elif 450 <= lambda_nm < 495:
        return "Blue"
    elif 425 <= lambda_nm < 450:
        return "Indigo"
    elif 380 <= lambda_nm < 425:
        return "Violet"


if __name__ == "__main__":
    print(solve(int(input())))
