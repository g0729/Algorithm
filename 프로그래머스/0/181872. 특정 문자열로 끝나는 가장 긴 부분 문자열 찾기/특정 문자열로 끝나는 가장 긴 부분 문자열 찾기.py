def solution(myString, pat):
    for idx in range(len(myString),-1,-1):
        if myString[:idx].endswith(pat):
            return myString[:idx]