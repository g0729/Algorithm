for _ in range(int(input())):
    g = int(input())
    v = [int(input()) for _ in range(g)]
    for i in range(g, int(1e9)):
        se = set()
        flag = True
        for a in v:
            if (a % i) in se:
                flag = False
                break
            se.add(a % i)

        if flag:
            print(i)
            break
