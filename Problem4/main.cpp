/**
 * @file       solution4.cpp
 * @author     Andreas Vasilakis
 * @date       17/03/2019
 * @version    1.0
 * 
 * @brief      Largest palindrome product
 * 
 * @scope
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
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

int maxPalindrome(void)
{
    int _max = 0;
    bool found = false;
    for(int i = 9; i >= 0; --i)
    {
        for(int j = 9; j >= 0; --j)
        {
            for(int k = 9; k >= 0; --k) {

                std::string _num = std::to_string(i) + std::to_string(j) + std::to_string(k) + std::to_string(k) + std::to_string(j) + std::to_string(i);
                _max = std::stoi(_num);

                if(_max < 10000 || _max >= 998001) {
                    continue;
                }

                for(int x = 999; x >=100 ; --x){
                    for(int y = 999; y >=100 ; --y) {
                        if(x*y == _max) {
                            found = true;
                        }
                    }
                    if(found)
                        break;
                }

                if(found)
                    break;
            }
            if(found)
                break;
        }
        if(found)
            break;
    }

    return _max;
}

int main (int argc, char *argv[])
{
    if (argc < 1) {
        std::cerr << "Usage: " << " n \n";
        return 1;
    }
    
    const std::string _name = std::string(argv[0]);
    
#ifdef EXECUTION_TIME_COMPUTATION
    auto start = high_resolution_clock::now(); 
#endif
    
// Solution (naive)
    std::cout << "Solution: " << maxPalindrome() << std::endl;

#ifdef EXECUTION_TIME_COMPUTATION
    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
	
	std::cout << "Time: " << duration.count() << " ms" << std::endl;
#endif

    return 0;
}
