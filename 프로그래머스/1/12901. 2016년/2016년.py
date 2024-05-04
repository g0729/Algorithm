def solution(a, b):
    answer = ''
    month=[31,29,31,30,31,30,31,31,30,31,30,31]
    
    day=-1
    for i in range(a-1):
        day+=month[i]
    ma={0:"FRI",1:"SAT",2:"SUN",3:"MON",4:"TUE",5:"WED",6:"THU"}
    return ma[(day+b)%7]