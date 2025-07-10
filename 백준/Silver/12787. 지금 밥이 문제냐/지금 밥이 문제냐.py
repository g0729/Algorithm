for _ in range(int(input())):
    op, num = input().split()

    if op == "1":
        print(int("".join(map(lambda x: bin(int(x))[2:].zfill(8), num.split("."))), 2))
    elif op == "2":
        temp = bin(int(num))[2:].zfill(64)
        parts = [temp[i : i + 8] for i in range(0, 64, 8)]
        print(".".join(map(lambda x: str(int(x, 2)), parts)))
