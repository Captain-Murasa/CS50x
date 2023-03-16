# TODO
height = ''
while not(height.isdigit()) or not(1 <= int(height) <= 8):
    height = input("Height: ")
height = int(height)

for i in range(height):
    for j in range(height * 2 + 2):
        if height - i - 1 > j or j in [height, height + 1]:
            print(' ', end='')
        elif height - i - 1 <= j <= height + 2 + i:
            print('#', end='')
    print()