import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    se = set([i for i in list(map(int, input().split()))[1:]])
    parties = [set(list(map(int, input().split()))[1:]) for i in range(m)]
    while True:
        initial_size = len(se)

        for party in parties:
            if not se.isdisjoint(party):
                se.update(party)

        if initial_size == len(se):
            break

    res = sum([1 if se.isdisjoint(party) else 0 for party in parties])

    print(res)


if __name__ == "__main__":
    solve()
