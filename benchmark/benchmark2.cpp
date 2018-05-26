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
    std::cout<<"Existing:"<<std::endl;
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        t_start = clock();
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.insert(value);
        }
        t_start = clock();
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value = rand();
            tree.exists(value);
        }
        t_end= clock() - t_start;
        std::cout<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
    }
}
/*10^1 : 1.2e-05
10^2 : 5.6e-05
10^3 : 0.000968
10^4 : 0.004176
10^5 : 0.054656
10^6 : 1.16417
10^7 : 23.8459
10^8 : 376.19*/
