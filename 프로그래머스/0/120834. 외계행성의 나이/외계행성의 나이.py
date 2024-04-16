def solution(age):
    return ''.join(chr(ord(c)-ord('0')+ord('a')) for c in str(age))