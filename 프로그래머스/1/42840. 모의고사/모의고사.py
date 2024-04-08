def solution(answers):
    answer = []
    num1,num2,num3=[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]
    cnt=[0 for _ in range(3)]
    for i in range(len(answers)):
        if answers[i]==num1[i%len(num1)]:
            cnt[0]+=1
        if answers[i]==num2[i%len(num2)]:
            cnt[1]+=1
        if answers[i]==num3[i%len(num3)]:
            cnt[2]+=1
    for i in range(1,4):
        if cnt[i-1]==max(cnt):
            answer.append(i)
    return answer