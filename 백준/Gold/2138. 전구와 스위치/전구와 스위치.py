def cal(arr):
    cnt = 0
    for i in range(1, n):
        if arr[i - 1] == 1:
            for j in range(i - 1, min(n, i + 2)):
                arr[j] = (arr[j] + 1) % 2
            cnt += 1

    if arr[-1] == 1:
        return -1
    else:
        return cnt


n = int(input())
A = list(map(int, input().rstrip()))
A = [0 if A[idx] == a else 1 for idx, a in enumerate(list(map(int, input().rstrip())))]

A2 = list(A)
A[0] = (A[0] + 1) % 2
A[1] = (A[1] + 1) % 2
temp = cal(A)
answer = [-1 if temp == -1 else temp + 1, cal(A2)]
if answer[0] == -1 and answer[1] == -1:
    print(-1)
elif answer[0] == -1 or answer[1] == -1:
    print(max(answer))
else:
    print(min(answer))
