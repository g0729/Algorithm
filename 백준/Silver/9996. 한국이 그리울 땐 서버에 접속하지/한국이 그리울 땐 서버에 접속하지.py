t=int(input())

pat=input()

star=pat.find('*')
left=pat[:star]
right=pat[star+1:]

for _ in range(t):
    s=input()

    if left in s and right in s:
        temp1=s.find(left)
        temp2=s.find(right)

        if temp1==0 and s[::-1].index(right[::-1])==0 and temp1+len(left)<=temp2:
            print('DA')
            continue
    
    print('NE')