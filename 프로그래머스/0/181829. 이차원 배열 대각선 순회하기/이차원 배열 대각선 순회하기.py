def solution(board, k):
    return sum(a for i,row in enumerate(board) for j,a in enumerate(row) if i +j <=k)