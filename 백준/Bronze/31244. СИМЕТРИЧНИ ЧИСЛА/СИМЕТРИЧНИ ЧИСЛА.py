import sys
input = sys.stdin.readline


def solve():
    a,b,c,=map(int,input().split())
    if a==b==c:
        print(f"{a}{b}{c}")
    elif b==c:
        print(f"{a}{b}{b}{a}")
    elif a==c:
        print(f"{a}{b}{a}")
    else:
        print(f"{a}{b}{c}{b}{a}")
    

if __name__ == "__main__":
    solve()