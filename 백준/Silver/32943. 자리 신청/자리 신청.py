x, c, k = map(int, input().split())
is_booked = [False] * (c + 1)
students = [0] * (x + 1)
v = [tuple(map(int, input().split())) for _ in range(k)]
v = sorted(v, key=lambda x: x[0])

for _, s, n in v:
    if is_booked[s]:
        continue
    is_booked[s] = True

    if students[n] != 0:
        is_booked[students[n]] = False
    students[n] = s


for i in range(1, x + 1):
    if students[i] == 0:
        continue
    print(i, students[i])
