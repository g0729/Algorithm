a, b, c = map(int, input().split())

normal = {key: int(value) for key, value in [input().split() for _ in range(a)]}
special = {key: int(value) for key, value in [input().split() for _ in range(b)]}
service = set([input() for _ in range(c)])
normal_cost = 0
special_cost = 0
service_cnt = 0

for _ in range(int(input())):
    menu = input()
    normal_cost += normal.get(menu, 0)
    special_cost += special.get(menu, 0)

    if menu in service:
        service_cnt += 1

if (special_cost and normal_cost < 20000) or (service_cnt and special_cost + normal_cost < 50000) or (service_cnt >= 2):
    print("No")
else:
    print("Okay")
