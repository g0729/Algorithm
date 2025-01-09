n = int(input())

for i in range(n, 2, -1):
    print(f"{i} bottles of beer on the wall, {i} bottles of beer.\nTake one down and pass it around, {i-1} bottles of beer on the wall.\n")

if n != 1:
    print("2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n")
print("1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n")
if n != 1:
    print(f"No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, {n} bottles of beer on the wall.")
else:
    print("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 1 bottle of beer on the wall.")
