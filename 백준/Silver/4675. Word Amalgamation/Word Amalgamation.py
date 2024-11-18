from collections import defaultdict

dic = defaultdict(list)

while True:
    s = input()
    if s == "XXXXXX":
        break
    dic["".join(sorted(s))].append(s)

for key, value in dic.items():
    dic[key] = sorted(value)
    
while True:
    s = input()
    if s == "XXXXXX":
        break
    temp = "".join(sorted(s))
    if temp in dic:
        print("\n".join(dic[temp]))
    else:
        print("NOT A VALID WORD")
    print("******")
