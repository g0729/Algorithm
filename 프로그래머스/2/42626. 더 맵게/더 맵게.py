import heapq


def solution(scoville, k):
    heapq.heapify(scoville)
    res = 0
    while scoville[0] < k:
        if len(scoville) <= 1:
            return -1
        next = heapq.heappop(scoville) + heapq.heappop(scoville) * 2
        heapq.heappush(scoville, next)
        res += 1
    return res
