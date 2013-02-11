//  2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
//  https://projecteuler.net/problem=5

#include <iostream>
#include <vector>

using namespace std;

bool divisibleByRange(int number, int from, int to)
{
    bool isFind = true;
    for (int j = from; j <= to; j++) {
        if(number % j != 0)
            isFind = false;
    }
    return isFind;
}

int main(int argc, const char * argv[])
{
    vector<int> v;
    bool find = false;
    int i = 0;

    while(!find)
    {
        i++;
        find = divisibleByRange(i, 1, 20);
    }
    cout << i;
}

