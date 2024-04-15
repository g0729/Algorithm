def solution(dots):
    a=[min([dots[i][0] for i in range(4)]),min([dots[i][1] for i in range(4)])]
    b=[max([dots[i][0] for i in range(4)]),max([dots[i][1] for i in range(4)])]
    
    return (b[0]-a[0])*(b[1]-a[1])