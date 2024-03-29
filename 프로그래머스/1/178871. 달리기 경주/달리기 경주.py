def solution(players, callings):
    answer = []
    name_to_rank={name:idx+1 for idx,name in enumerate(players)}
    rank_to_name={idx+1:name for idx,name in enumerate(players)}
    
    for player in callings:
        rank=name_to_rank[player]
        prev_name=rank_to_name[rank-1]
        name_to_rank[player]=rank-1
        name_to_rank[prev_name]=rank
        rank_to_name[rank]=prev_name
        rank_to_name[rank-1]=player
        
    for key,vals in rank_to_name.items():
        answer.append(vals)
    return answer