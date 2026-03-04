from cs50 import get_string

card = get_string("Number: ")

sum1 = 0
sum2 = 0
length = len(card)

# Multiply every other digit by 2
for i in range(length - 2, -1, -2):
    num = int(card[i]) * 2
    sum1 += num // 10 + num % 10
    
# Add remaining digits
for i in range(length - 1, -1, -2):
    sum2 += int(card[i])
    
total1 = sum1 + sum2

# Check validity
if total1 % 10 != 0:
    print("INVALID")
else:
    first = int(card[0])
    first_two = int(card[:2])
    
    if length == 15 and (first_two == 34 or first_two == 37):
        print("AMEX")
    elif length == 16 and 51 <= first_two <= 55:
        print("MASTERCARD")
    elif (length == 13 or length == 16) and first == 4:
        print("VISA")
    else:
        print("INVALID")