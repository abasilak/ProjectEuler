/**
 * @file       solution3.cpp
 * @author     Andreas Vasilakis
 * @date       10/03/2019
 * @version    1.0
 * 
 * @brief      Largest prime factor
 * 
 * @scope
 * 
 * What is the largest prime factor of the number n?
 * 
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <assert.h>

#ifdef EXECUTION_TIME_COMPUTATION
#include <chrono> 
using namespace std::chrono; 
#endif 

long maxPrimeFactor(long n)
{
    long _max = 1;
    for(long i = 2; i < n/i; i++) {
        while(n%i == 0) {
            _max = std::max(_max, i);
            n = n/i;
        }
    }

    if(n > 0) {
        _max = std::max(_max, n);
    }

    return _max;
}

int main (int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " n \n";
        return 1;
    }
    
    const std::string _name = std::string(argv[0]);
    const long         _n    = std::stol(argv[1]);
    
#ifdef EXECUTION_TIME_COMPUTATION
    auto start = high_resolution_clock::now(); 
#endif
    
// Solution (naive)
    long _max = maxPrimeFactor(_n);

    std::cout << "Solution(" << _n << "): " << _max << std::endl;

#ifdef EXECUTION_TIME_COMPUTATION
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
	
	std::cout << "Time: " << duration.count() << " ms" << std::endl;
#endif

    return 0;
}
