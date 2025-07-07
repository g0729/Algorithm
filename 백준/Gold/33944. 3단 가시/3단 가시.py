import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    x = int(input())
    v = list(map(int, input().split()))
    point = []
    cur, cnt = v[0], 1

    for i in range(1, x):
        if v[i] - v[i - 1] == 1:
            cnt += 1
        else:
            point.append((cur, cnt))
            cur, cnt = v[i], 1

    point.append((cur, cnt))

    possible_landings = {0}

    for p_start, p_len in point:
        p_last = p_start + p_len - 1
        next_possible_landings = set()

        for land_pos in possible_landings:
            if land_pos > p_last:
                next_possible_landings.add(land_pos)
                continue

            for k in range(1, 4):
                jump_pos = p_last - (4 - k)

                if land_pos <= jump_pos < p_start:
                    new_land_pos = jump_pos + 4
                    next_possible_landings.add(new_land_pos)

        possible_landings = next_possible_landings

        if not possible_landings:
            break

    if possible_landings:
        return "POSSIBLE"
    else:
        return "IMPOSSIBLE"


if __name__ == "__main__":
    for _ in range(int(input())):
        print(solve())
