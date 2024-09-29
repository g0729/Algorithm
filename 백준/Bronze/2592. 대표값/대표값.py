from collections import Counter

v = [int(input()) for _ in range(10)]

print(sum(v) // 10)
print(Counter(v).most_common(1)[0][0])
