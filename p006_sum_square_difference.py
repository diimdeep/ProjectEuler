__author__ = 'dmitrywolf'

# The sum of the squares of the first ten natural numbers is,
#
# 12 + 22 + ... + 102 = 385
# The square of the sum of the first ten natural numbers is,
#
# (1 + 2 + ... + 10)2 = 552 = 3025
# Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
#
# Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

import math

j = 0
def sumOfTheSquaresOfTheFirst(number):
    result = 0
    for i in range(number+1):
        result += math.pow(i, 2)
    return result

def squareOfTheSumOfTheFirst(number):
    result = 0
    for i in range(number+1):
        result += i
    result = math.pow(result, 2)
    return result


print squareOfTheSumOfTheFirst(100) - sumOfTheSquaresOfTheFirst(100)