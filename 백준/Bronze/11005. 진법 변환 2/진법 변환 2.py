import sys

print = sys.stdout.write
n, b = map(int, input().split())
ans = ""
while n:
    n, mod = divmod(n, b)
    if mod >= 10:
        ans += chr(mod - 10 + ord("A"))
    else:
        ans += str(mod)
print(ans[::-1])
