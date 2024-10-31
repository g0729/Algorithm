s = input()
n = int(s)
digit = 1
while digit * 10 < n:
    a = (n % (digit * 10)) // digit
    n -= a * digit
    if a >= 5:
        n += digit * 10
    digit *= 10
print(n)
