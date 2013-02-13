//  Summation of primes
//  Problem 10
//  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

//  Find the sum of all the primes below two million.

#include <iostream>
#include <complex>

using namespace std;

bool isPrime(int number)
{
    for (int i = 2; i < number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    long sumOfPrimes = 0;
    int i = 2;
    while (i < 2000000){
        if(isPrime(i)){
            sumOfPrimes += i;
            //cout << i << endl;
        }
        i += 1;
    }
    cout << i <<", "<< sumOfPrimes;

}

