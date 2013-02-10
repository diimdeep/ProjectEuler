//  https://projecteuler.net/problem=3
//  The prime factors of 13195 are 5, 7, 13 and 29.
//  What is the largest prime factor of the number 600851475143 ?

//  http://en.wikipedia.org/wiki/Prime_number
//  http://en.wikipedia.org/wiki/Factoring_integers#Factoring_algorithms
//  http://www.wolframalpha.com/input/?i=600851475143+prime+factor

#include <iostream>
#include <algorithm>
#include <complex>
#include <thread>
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    int numthreads = 4;
    cout << "Working in " << numthreads << " threads." << endl;
    
    long number = 600851475143659977;
    

    long numbers = number/2/numthreads;
    long extra  = number/2 % numthreads;
    
    long start = 1;
    long end = numbers;
    
    bool stop = false;
    
    vector <thread> workers;
    
    vector<long> maxs;
    
    for (int t = 1; t <= numthreads; t++) {
        if(t == numthreads)
            end += extra;
        
        workers.push_back(thread([=, &stop, &maxs]()
        {
            for (long i = start; start < end; i++) {
                if(number % i == 0){
                    maxs.push_back(i);
                }
                if(stop)
                    break;
            }
        }));
        
        start = end;
        end = start + numbers;
    }
    
    workers.push_back(thread([=, &stop, &maxs]()
                             {
                                 int i = 0;
                                 auto duration = chrono::seconds(2);
                                 while(!stop)
                                 {
                                     if(maxs.size() > i)
                                     {
                                         long num = maxs[i];
                                         cout << "Find devisor number: " << num;
                                         bool isPrime = true;
                                         for (int j=2; j < num; j++) {
                                             if(num % j == 0)
                                                 isPrime = false;
                                         }
                                         if(isPrime)
                                             cout << " and it is prime number !";
                                         cout << endl;
                                         i++;
                                     }
                                     this_thread::sleep_for(duration);
                                 }
                             }));

    cout << "Press Enter to stop this madness." << endl << endl;
    getchar();
    stop = true;
    
    for(thread& t : workers)
        t.join();
    
    cout << "I'm quit!";
    return 0;
}

