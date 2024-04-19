def solution(sides):
    return (sum(sides)-max(sides))+(max(sides)-abs(sides[0]-sides[1])-1)