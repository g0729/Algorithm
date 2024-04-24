from collections import Counter

s = input()
a = Counter(s.lower()).most_common(2)
if len(a) != 1 and a[0][1] == a[1][1]:
    print("?")
else:
    print(a[0][0].upper())
