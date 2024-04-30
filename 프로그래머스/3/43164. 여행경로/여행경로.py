import copy


def dfs(now, cnt, edges, index_to_name, visited):

    if cnt == n:
        answers.append(copy.deepcopy(answer))
        return

    for i in range(len(edges[now])):
        next = edges[now][i]
        if visited[now][i]:
            continue
        visited[now][i] = True
        answer.append(index_to_name[next])
        dfs(next, cnt + 1, edges, index_to_name, visited)
        answer.pop()
        visited[now][i] = False


def solution(tickets):
    global answer, n, answers
    answers = []
    answer = ["ICN"]
    n = len(tickets)
    se = set()
    for a, b in tickets:
        se.add(a)
        se.add(b)

    name_to_index = {name: idx for idx, name in enumerate(se)}
    index_to_name = {idx: name for idx, name in enumerate(se)}

    edges = [[] for _ in range(len(se))]

    for a, b in tickets:
        a, b = name_to_index[a], name_to_index[b]
        edges[a].append(b)

    visited = [[False] * len(edges[i]) for i in range(len(edges))]
    dfs(name_to_index["ICN"], 0, edges, index_to_name, visited)
    answers.sort()
    return answers[0]
