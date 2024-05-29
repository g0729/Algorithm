def distance(x, y):
    return x**2 + y**2


n, k = map(int, input().split())
v = []
for _ in range(n):
    pi = int(input())
    points = list(map(int, input().split()))
    furthest = max(distance(points[i * 2], points[i * 2 + 1]) for i in range(pi))
    v.append(furthest)
v.sort()

print(f"{v[k - 1]}.00")
