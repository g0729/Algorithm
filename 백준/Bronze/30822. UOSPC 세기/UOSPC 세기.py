from collections import Counter

n = int(input())
c = Counter(input())
print(min(c["u"], c["o"], c["s"], c["p"], c["c"]))
