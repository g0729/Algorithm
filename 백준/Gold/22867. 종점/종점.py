import heapq


def parse(s):
    total = 0
    s = s.split(":")
    s = s[:-1] + s[-1].split(".")
    total = int(s[0]) * 1000 * 60 * 60 + int(s[1]) * 1000 * 60 + int(s[2]) * 1000 + int(s[3])
    return total


buses = [tuple(input().split(" ")) for _ in range(int(input()))]

buses.sort(key=lambda x: x[0])

res = 0
q = []
for bus in buses:
    time_in, time_out = parse(bus[0]), parse(bus[1])

    while q and q[0] <= time_in:
        heapq.heappop(q)
    heapq.heappush(q, time_out)
    res = max(res, len(q))

print(res)
