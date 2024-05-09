import re

def solution(skill, skill_trees):
    answer=0
    
    for skill_tree in skill_trees:
        s=re.sub(r'[^{}]'.format(skill),'',skill_tree)
        if s==skill[:len(s)]:
            answer+=1
    return answer