def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1])
    now=-30001
    for a,b in routes:
        if now<a:
            answer+=1
            now=b
    return answer