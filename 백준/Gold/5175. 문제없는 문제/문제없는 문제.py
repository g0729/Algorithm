for test_case in range(int(input())):

    m, n = map(int, input().split())
    v = [0] * n
    select_all = (1 << m) - 1
    for i in range(n):
        for a in map(int, input().split()):
            v[i] |= 1 << (a - 1)

    res_cnt = 30
    res = 0
    for mask in range(1, (1 << n)):
        cur_mask = 0
        cnt = 0
        for i in range(n):
            if (mask >> i) & 1:
                cnt += 1
                cur_mask |= v[i]

        if cur_mask == select_all:
            if res_cnt > cnt:
                res_cnt = cnt
                res = mask

    print(f"Data Set {test_case+1}: ", end="")

    for i in range(n):
        if (res >> i) & 1:
            print(chr(i + ord("A")), end=" ")
    print("\n")
