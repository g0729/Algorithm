def solution(numbers):
    nums=[ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    for num,s in enumerate(nums):
        numbers=numbers.replace(s,str(num))
        
    return int(numbers)