from collections import Counter
def solution(nums):
    return min(len(Counter(nums).items()),len(nums)//2)