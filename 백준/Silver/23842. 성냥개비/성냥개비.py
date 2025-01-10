v = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

n = int(input())


def matches(num):
    return v[num // 10] + v[num % 10]


for i in range(100):
    for j in range(99 - i):
        sum = i + j

        if matches(i) + matches(j) + 4 + matches(sum) == n:
            print(f"{i:02d}+{j:02d}={sum:02d}")
            exit(0)

print("impossible")
