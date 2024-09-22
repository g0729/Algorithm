from collections import deque
import sys

input = sys.stdin.readline
n, k = map(int, input().split())
v = [0] + list(map(int, input().split()))


def check(target):

    visited = [False] * (n + 1)
    visited[n] = True
    cur = n
    counts = k
    while True:

        if v[cur] == 1:
            next = cur - target
            counts -= 1
        else:
            next = cur + 1
        if next <= 1:
            return True
        if counts == 0:
            return False
        if visited[next]:
            return False
        cur = next
        visited[cur] = True
    return False


def bin_search():
    left, right = 0, n + 1

    while left + 1 < right:
        mid = (left + right) // 2
        if check(mid):
            right = mid
        else:
            left = mid

    return right


print(bin_search())
