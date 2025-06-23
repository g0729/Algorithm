s=input()
print("-"*s.find("U")+"U"+"C"*(s.rfind("F")-s.find("U")-1)+"F"+"-"*(len(s)-s.rfind('F')-1))