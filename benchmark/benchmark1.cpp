#include <iostream>
#include <locale>
#include <ctime>
#include <cmath>
#include <fstream>
#include "tree.hpp"


int main() {
    setlocale(LC_ALL, "RUS");
    clock_t  t_start;
    clock_t  t_end;
    BSTree::Tree tree;
    std::freopen("tree_bench.txt", "w", stdout);
    std::ofstream out("bench2.txt");
    for (size_t exp = 1; exp < 9;  exp ++ ) {
        int value;
        for(size_t num_el = 1; num_el <= pow(10,exp); num_el++) {
            value  = rand();
            tree.insert(value);
        }
        t_start = clock();
        tree.print_graphics();
        t_end= clock() - t_start;
        out<<"10^"<<exp<<" : "<<(float)t_end/CLOCKS_PER_SEC<<std::endl;
    }
}
/*
10^1 : 0.00016
10^2 : 0.0008
10^3 : 0.008506
10^4 : 0.089174
10^5 : 0.91302
10^6 : 9.95144
10^7 : 107.371*/
