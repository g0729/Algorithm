def solution(dirs):
    visited = [[[False] * 4 for _ in range(11)] for _ in range(11)]
    cur = (5, 5)
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    dir = {"U": 0, "R": 1, "D": 2, "L": 3}
    answer = 0
    se=set()
    for c in dirs:
        cur_dir = dir[c]
        next = (cur[0] + dx[cur_dir], cur[1] + dy[cur_dir])

        if 0 <= next[0] <= 10 and 0 <= next[1] <= 10:
            if str(cur+next) not in se and str(next+cur) not in se:
                answer+=1
                se.add(str(cur+next))
            cur=next
    return answer
