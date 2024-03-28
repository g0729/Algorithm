a=input()
b=input()

print(a)
print(b)

for i in range(0,len(b)):
    print((int(a)*int(b[len(b)-i-1])))

print(int(a)*int(b))