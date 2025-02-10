n, a, b = map(int, input().split())
s, t = map(int, input().split())

if (a + 1) <= s <= (b - 1) and (a + 1) <= t <= (b - 1):
    print("City")
elif (1 <= s <= a and 1 <= t <= a) or (b <= s <= n and b <= t <= n):
    print("Outside")
else:
    print("Full")
