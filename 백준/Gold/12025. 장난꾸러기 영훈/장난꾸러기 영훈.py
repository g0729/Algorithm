s = input()
n = int(input())

s = s.replace("6", "1")
s = s.replace("7", "2")
cnt = s.count("1") + s.count("2")
s = list(s)
if 2**cnt < n:
    print("-1")
else:
    n = bin(n - 1)[2:]
    n = "0" * (cnt - len(n)) + n

    idx = 0

    for i in range(len(s)):
        if s[i] == "1" or s[i] == "2":
            if n[idx] == "1":
                if s[i] == "1":
                    s[i] = "6"
                else:
                    s[i] = "7"
            idx += 1

    print("".join(s))
