# TODO
height = ''
while not(height.isdigit()) or not(1 <= int(height) <= 8):
    height = input("Height: ")
height = int(height)

for i in range(height):
    for j in range(height):
        if j >= height - i - 1:
            print('#', end='')
        else:
            print(' ', end='')
    print()