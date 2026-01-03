import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def solve():
    s = input().rstrip()
    if not "." in s:
        print(s + "/1")
    elif not "(" in s:
        p = len(s) - s.find(".") - 1
        nume, deno = int(s.replace(".", "")), 10**p
        div = gcd(nume, deno)
        print(nume // div, "/", deno // div, sep="")
    else:
        nonCircular = s.find("(") - s.find(".") - 1
        decimal = len(s) - s.find(".") - 3
        circular = decimal - nonCircular

        deno = int("9" * circular + "0" * nonCircular)
        nume = int(s.replace(".", "").replace("(", "").replace(")", "")) - int(s[: s.find("(")].replace(".", ""))
        div = gcd(nume, deno)
        print(nume // div, "/", deno // div, sep="")


if __name__ == "__main__":
    solve()
