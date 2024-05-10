from collections import defaultdict


def solution(record):
    id_to_name = defaultdict(str)
    for s in record:
        s = s.split(" ")
        if len(s) == 2:
            continue
        id_to_name[s[1]] = s[2]
    answer = []
    for s in record:
        s = s.split(" ")
        if s[0] == "Enter":
            answer.append(f"{id_to_name[s[1]]}님이 들어왔습니다.")
        elif s[0] == "Leave":
            answer.append(f"{id_to_name[s[1]]}님이 나갔습니다.")
    return answer
