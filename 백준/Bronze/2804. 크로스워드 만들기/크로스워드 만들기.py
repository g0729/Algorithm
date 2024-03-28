a,b=map(str,input().split())

for i in range(len(a)):
    if a[i] in b:
        column=i
        row=b.index(a[i])
        break
  
for i in range(len(b)):
    if i == row:
      print(a)
    else:
        print('.'*column+b[i]+'.'*(len(a)-column-1))
