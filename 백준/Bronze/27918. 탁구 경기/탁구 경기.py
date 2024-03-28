N = int(input())
D_count = 0
P_count = 0
W = []

for i in range(N):
        W.append(input())
for i in W:
        if i == 'D':
                D_count += 1
        elif i == 'P':
                P_count += 1
        if abs(D_count - P_count) >= 2:
                break
print("{}:{}".format(D_count, P_count))