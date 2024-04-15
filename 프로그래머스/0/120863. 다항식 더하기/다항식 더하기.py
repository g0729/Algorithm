def solution(polynomial):
    cnt=[0,0]
    for a in polynomial.split():
        if a=='+':
            continue
        if 'x'in a:
            if len(a)==1:
                cnt[0]+=1
            else:
                cnt[0]+=int(a[:-1])
        else:
            cnt[1]+=int(a)
    answer=''
    if cnt[0]!=0:
        if cnt[0]==1:
            answer+='x'
        else:
            answer+=f"{cnt[0]}x"
    if cnt[1]!=0:
        if cnt[0]!=0:
            answer+=f" + {cnt[1]}"
        else:
            answer+=str(cnt[1])
    return answer