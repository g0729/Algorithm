s=input()

if len(s)==4:
    print("20")
elif len(s)==3:
    if s[1]=="0":
        print(10+int(s[2]))
    else:
        print(int(s[0])+10)
else:
    print(int(s[0])+int(s[1]))
    