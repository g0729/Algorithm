import sys


def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    N = int(input_data[0])
    events = []

    idx = 1
    for _ in range(N):
        start_str = input_data[idx]
        end_str = input_data[idx + 1]
        idx += 2

        sy, sm = map(int, start_str.split("-"))
        ey, em = map(int, end_str.split("-"))

        start_val = sy * 12 + (sm - 1)
        end_val = ey * 12 + (em - 1)

        events.append((start_val, 1))
        events.append((end_val + 1, -1))

    events.sort(key=lambda x: (x[0], x[1]))

    max_friends = -1
    best_month_val = -1
    current_friends = 0

    for time_val, delta in events:
        current_friends += delta

        if current_friends > max_friends:
            max_friends = current_friends
            best_month_val = time_val
    best_y = best_month_val // 12
    best_m = best_month_val % 12 + 1

    print(f"{best_y:04d}-{best_m:02d}")


if __name__ == "__main__":
    solve()
