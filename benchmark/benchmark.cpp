#include <iostream>
#include <locale>
#include <ctime>
#include <cmath>
#include "tree.hpp"

int main() {
    setlocale(LC_ALL, "RUS");
    clock_t  t_start;
    clock_t  t_end;
    BSTree::Tree tree;
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        std::cout<<"Adding:"<<std::endl;
        t_start = clock();
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.insert(value);
        }
        t_end= clock() - t_start;
        std::cout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
        std::cout<<"Removing:"<<std::endl;
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.remove(value);
        }
        t_end= clock() - t_start;
        std::cout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
    }
}


/*
Adding:
10^1 : 2e-05
Removing:
10^1 : 5.8e-05
Adding:
10^2 : 3e-05
Removing:
10^2 : 5.7e-05
Adding:
10^3 : 0.000475
Removing:
10^3 : 0.000763
Adding:
10^4 : 0.006438
Removing:
10^4 : 0.010102
Adding:
10^5 : 0.090446
Removing:
10^5 : 0.155896
Adding:
10^6 : 1.44197
Removing:
10^6 : 2.63441
Adding:
10^7 : 24.2168
Removing:
10^7 : 48.1904
Adding:
10^8 : 377.816
Removing:
10^8 : 754.782
*/
