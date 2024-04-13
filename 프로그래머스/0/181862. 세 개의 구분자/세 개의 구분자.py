import re
def solution(myStr):
    myStr=re.sub(r"[abc]"," ",myStr)
    return myStr.split() if len(myStr.split())!=0 else ["EMPTY"]
    