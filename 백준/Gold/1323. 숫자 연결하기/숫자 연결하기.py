import sys

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    visited = [False] * k

    cur = n % k
    if cur == 0:
        return 1

    visited[cur] = True
    A = (10 ** (len(str(n)))) % k
    res = 1
    while True:
        res += 1
        next = (((cur % k) * A) % k + n % k) % k

        if next == 0:
            return res
        if visited[next]:
            return -1

        visited[next] = True

        cur = next


if __name__ == "__main__":
    print(solve())
