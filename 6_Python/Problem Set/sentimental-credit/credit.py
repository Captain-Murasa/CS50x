# TODO
from cs50 import get_string, get_int

def main():
    number = get_int("Number: ")
    number = str(number)

    if AE(number):
        print('AMEX')
    elif MC(number):
        print('MASTERCARD')
    elif Visa(number):
        print('VISA')
    else:
        print('INVALID')


# Validation of the input number
def validate(number):
    sum = 0
    for i in range(-2, -len(number) - 1, -2):
        tmp = int(number[i]) * 2
        if tmp > 9:
            tmp = int(tmp / 10) + int(tmp % 10)
        sum += tmp
    for i in range(-1, -len(number) - 1, -2):
        sum += int(number[i])
    return not(sum % 10)


# If the input is a American Express number
def AE(number):
    if len(number) != 15 or number[:2] not in ['34', '37']:
        return False
    if not(validate(number)):
        return False
    return True


# If the input is a MasterCard number
def MC(number):
    if len(number) != 16 or number[:2] not in ['51', '52', '53', '54', '55']:
        return False
    if not(validate(number)):
        return False
    return True


# # If the input is a Visa number
def Visa(number):
    if len(number) not in [13, 16] or number[0] != '4':
        return False
    if not(validate(number)):
        return False
    return True


if __name__ == "__main__":
    main()