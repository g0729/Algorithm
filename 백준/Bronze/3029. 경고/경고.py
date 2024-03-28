a=input()
b=input()

aTime=60*60*(int(a[0:2]))+60*(int(a[3:5]))+int(a[6:8])
bTime=60*60*(int(b[0:2]))+60*(int(b[3:5]))+int(b[6:8])

res=bTime-aTime

if res<=0:
    res+=24*60*60
print('%02d:%02d:%02d'%(res//(60*60),(res//60)%60,res%60))