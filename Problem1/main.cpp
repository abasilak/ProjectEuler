/**
 * @file       solution1.cpp
 * @author     Andreas Vasilakis
 * @date       15/02/2019
 * @version    1.0
 * 
 * @brief      Multiples of 3 and 5
 * 
 * @scope
 * 
 * If we list all the natural numbers below 10 that are multiples
 * of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <assert.h>

#ifdef EXECUTION_TIME_COMPUTATION
#include <chrono> 
using namespace std::chrono; 
#endif 

int sum_of(int x, int n)
{
    int    p = n/x;
    return x * (p*(p+1))/2;
}

int main (int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " n \n";
        return 1;
    }
    
    const std::string _name = std::string(argv[0]);
    const int         _n    = std::stoi(argv[1]);
    
#ifdef EXECUTION_TIME_COMPUTATION
    auto start = high_resolution_clock::now(); 
#endif
    
// Solution (naive)
    int _sum = 0;
    for(int i=0; i<_n; i++) {
        if(i%3 == 0 || i%5 == 0)
            _sum += i;
    }
    std::cout << "Solution(" << _n << "): " << _sum << std::endl;

#ifdef EXECUTION_TIME_COMPUTATION
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
	
	std::cout << "Time: " << duration.count() << " ms" << std::endl;
#endif

// Solution (fast)
#ifdef EXECUTION_TIME_COMPUTATION
    start = high_resolution_clock::now(); 
#endif

    _sum = sum_of(3,_n-1) + sum_of(5,_n-1) - sum_of(15,_n-1);  

    std::cout << "Solution(" << _n << "): " << _sum << std::endl;
    
#ifdef EXECUTION_TIME_COMPUTATION
    stop     = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start); 
	
	std::cout << "Time: " << duration.count() << " ms" << std::endl;
#endif

    return 0;
}
