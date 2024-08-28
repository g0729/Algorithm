a, b = input().split()
idx = len(a) - a.index(".") - 1
a, b = int(a.replace(".", "")), int(b)
res = str(a**b)
idx = idx * b
if len(res) > idx:
    res = res[: len(res) - idx] + "." + res[len(res) - idx :]
else:
    idx = idx - len(res)
    res = "0." + "0" * idx + res

print(res)
