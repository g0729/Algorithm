v = [tuple(input().split()) for _ in range(7)]

print(max(v, key=lambda x: int(x[1]))[0])
