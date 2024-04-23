def solution(emergency):
    emergency=[[emergency[i],i] for i in range(len(emergency))]
    emergency.sort(key=lambda x:-x[0])
    for i in range(len(emergency)):
        emergency[i][0]=i+1
    emergency.sort(key=lambda x:x[1])
    return [emergency[i][0] for i in range(len(emergency))]