import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def solve():

    dic = {
        "CU": "see you",
        ":-)": "I’m happy",
        ":-(": "I’m unhappy",
        ";-)": "wink",
        ":-P": "stick out my tongue",
        "(~.~)": "sleepy",
        "TA": "totally awesome",
        "CCC": "Canadian Computing Competition",
        "CUZ": "because",
        "TY": "thank-you",
        "YW": "you’re welcome",
        "TTYL": "talk to you later",
    }

    while True:
        s = input().strip()

        print(dic[s] if s in dic else s)

        if s == "TTYL":
            break


if __name__ == "__main__":
    solve()
