def f(N :int):
    if N >= 90:
        return 'A'
    elif N >= 80:
        return 'B'
    elif N>=70:
        return 'C'
    elif N>=60:
        return 'D'
    else:
        return "F"


n=int(input())

for i in range(n,101):
    print(f(i),end=' ')