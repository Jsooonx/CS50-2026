from cs50 import get_int

# Ask for height
while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break
    
for i in range(1, height + 1):
    
    # Left spaces
    print(" " * (height - i), end="")
    
    # Left hashes
    print("#" * i, end="")
    
    # Gap
    print("  ", end="")
    
    # Right hashes
    print("#" * i)