# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
# Find the largest palindrome made from the product of two 3-digit numbers.
# https://projecteuler.net/problem=4

def is_palindrome(s):
    if s == '':
        return True
    else:
        if s[0] == s[-1]:
            return is_palindrome(s[1:-1])
        else:
            return False

def iter_palindrome(s):
    for i in range(0, len(s)/2):
        if s[i] != s[-(i + 1)]:
            return False
    return True

def find_largest_palindrome_for_product(n):
    pol = []
    for i in reversed(xrange(n)):
        for j in reversed(xrange(n)):
            if is_palindrome(str(i*j)):
                pol.append(i*j)
    return max(pol)

pr = find_largest_palindrome_for_product(999)
print pr
