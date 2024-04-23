arr = [1, 1]
for i in range(2, 490):
    arr.append(arr[i - 2] + arr[i - 1])

while True:
    n = int(input())
    if n == -1:
        break

    print(f"Hour {n}: {arr[n-1]} cow(s) affected")
