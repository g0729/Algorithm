n = int(input())
for _ in range(n):
    s = input()
    c = s[-1]
    if c == "a":
        s = s[:-1] + "as"
    elif c == "i" or c == "y":
        s = s[:-1] + "ios"
    elif c == "l":
        s = s[:-1] + "les"
    elif c == "n":
        s = s[:-1] + "anes"
    elif s[-2] + c == "ne":
        s = s[:-2] + "anes"
    elif c == "o":
        s = s[:-1] + "os"
    elif c == "r":
        s = s[:-1] + "res"
    elif c == "t":
        s = s[:-1] + "tas"
    elif c == "u":
        s = s[:-1] + "us"
    elif c == "v":
        s = s[:-1] + "ves"
    elif c == "w":
        s = s[:-1] + "was"
    else:
        s = s + "us"
    print(s)
