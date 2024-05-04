def solution(n, words):
    answer = []
    se=set()
    se.add(words[0])
    for i in range(1,len(words)):
        if words[i][0]!=words[i-1][-1] or words[i] in se:
            return [i%n+1,i//n+1]
        se.add(words[i])
    return [0,0]