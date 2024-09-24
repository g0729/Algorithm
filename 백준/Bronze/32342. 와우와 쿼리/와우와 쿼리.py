import re

for _ in range(int(input())):
    s = input()
    res = sum([1 if s[i : i + 3] == "WOW" else 0 for i in range(len(s) - 2)])
    print(res)
