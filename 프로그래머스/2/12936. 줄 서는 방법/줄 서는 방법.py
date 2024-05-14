from math import factorial as fac


def solution(n, k):
    arr = list(range(1, n + 1))
    answer = []

    for i in range(n):
        cur = n - i - 1
        if k == 0:
            answer.append(arr[-1])
            arr.pop()
        elif fac(cur) >= k:
            answer.append(arr[0])
            arr.remove(arr[0])
        else:
            idx = (k - 1) // fac(cur)
            answer.append(arr[idx])
            arr.remove(arr[idx])
            k %= fac(cur)
    return answer
