n = int(input())
x = [0] + list(map(int, input().split()))
t = [0] + list(map(int, input().split()))

time = max(x[-1], t[-1])

for i in range(n - 1, -1, -1):
    cur_time = time + (x[i + 1] - x[i])
    time = max(cur_time, t[i])

print(time)
