s = input()

v1 = ["social", "history", "language", "literacy"]
v2 = ["bigdata", "public", "society"]

for a in v1:
    if a in s:
        print("digital humanities")
        exit(0)

for a in v2:
    if a in s:
        print("public bigdata")
        exit(0)
