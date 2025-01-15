from math import sqrt


def distance(x1, y1, x2, y2):
    return sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


xs, ys = map(int, input().split())
xe, ye, dx, dy = map(int, input().split())
dis = distance(xe, ye, xs, ys)
temp = gcd(dx, dy)
dx, dy = dx // temp, dy // temp
res_x, res_y = xe, ye
while True:
    xe, ye = xe + dx, ye + dy
    ndis = distance(xe, ye, xs, ys)

    if ndis > dis:
        break

    dis = ndis
    res_x, res_y = xe, ye

print(res_x, res_y)
