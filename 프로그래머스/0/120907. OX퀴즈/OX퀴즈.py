def solution(quiz):
    answer = []
    for q in quiz:
        a=q.split()
        if eval(''.join(a[:3]))==int(a[-1]):
            answer.append('O')
        else:
            answer.append('X')
            
    return answer
  