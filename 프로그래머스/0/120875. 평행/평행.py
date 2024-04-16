from itertools import combinations

def solution(dots):
    
    for a in combinations([0,1,2,3],2):
        set1=[]
        for j in range(4):
            if j not in a:
                set1.append(j)
        diff1=(dots[a[0]][1]-dots[a[1]][1])/(dots[a[0]][0]-dots[a[1]][0])
        diff2=(dots[set1[0]][1]-dots[set1[1]][1])/(dots[set1[0]][0]-dots[set1[1]][0])
        if diff1==diff2:
            return 1
        
    return 0
    