a = 1
while True:
    s = input()
    if s.split()[1] == "E":
        break
    print("Case ", a, ": ", sep="", end="")
    if not eval(s):
        print("false")
    else:
        print("true")
    a += 1
