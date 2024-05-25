import sys
from collections import defaultdict

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    v = list(map(int, input().split()))

    team_nums = [0] * 201
    for a in v:
        team_nums[a] += 1
    team_scores = [[] for _ in range(201)]
    idx = 1
    for a in v:
        if team_nums[a] != 6:
            continue
        team_scores[a].append(idx)
        idx += 1

    team_scores_idx = [(i, team_scores[i]) for i in range(len(team_scores)) if len(team_scores[i]) == 6]

    team_scores_idx.sort(key=lambda x: (sum(x[1][:4]), x[1][4]))

    print(team_scores_idx[0][0])
