v = ["Watermelon", "Pomegranates", "Nuts"]
n = int(input())
for i in range(3):
    a = int(input())
    if a <= n:
        print(v[i])
        exit(0)

print("Nothing")
