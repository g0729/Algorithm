n = int(input())
while n:
    temp = str(n)
    if temp.count("4") + temp.count("7") == len(temp):
        print(temp)
        break
    n -= 1
