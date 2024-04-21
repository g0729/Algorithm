def solution(phone_book):
    phone_book.sort(key=lambda x: len(x), reverse=True)
    
    se=set()
    
    for num in phone_book:
        if num in se:
            return False
        for i in range(1,len(num)):
            se.add(num[:i])
    return True