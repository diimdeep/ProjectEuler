# 10001st prime

# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
# What is the 10 001st prime number?
# https://projecteuler.net/problem=7

def isPrime(number):
    '''
    >>> isPrime(1)
    True

    >>> isPrime(11)
    True

    >>> isPrime(10)
    False
    '''
    for i in range(2, number):
        if number % i == 0:
            return False
    return True

number = 1
i = 0
while i < 10001:
    number += 1
    #print number
    if(isPrime(number)):
        i += 1
        print "i", i


print i, number

