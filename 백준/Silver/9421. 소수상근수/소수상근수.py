import sys

input = sys.stdin.readline
print = sys.stdout.write


def is_prime(num):

    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def cal(num):
    return sum(map(lambda x: int(x) ** 2, str(num)))


def f(num):

    visited = [False] * 500
    while num != 1:
        next = cal(num)
        if visited[next]:
            return False
        visited[next] = True
        num = next
    return True


n = int(input())

for i in range(7, n + 1):
    if is_prime(i) and f(i):
        print(str(i) + "\n")
