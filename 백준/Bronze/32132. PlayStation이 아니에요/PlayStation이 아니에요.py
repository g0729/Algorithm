n = int(input())
s = input()

while True:
    if s.find("PS5") == -1 and s.find("PS4") == -1:
        break
    s = s.replace("PS5", "PS")
    s = s.replace("PS4", "PS")
print(s)
