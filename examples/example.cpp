// пример работы конструктора и методов вывода дерева, оператора =
#include <iostream>
#include <cstring>//char* strchr(); проверить есть ли в итог реализации 0,1
#include <cstdlib>//int atoi();
#include <string>
#include "tree.hpp"

using namespace BSTree;

int main(){
  Tree der0;
  Tree der1{1,2,75,85,95,15,25,35,45,65};
  Tree der2{der1};
  std::cout<<"было созданно 3 дерева:"<<std::endl ;
  std::cout<<"дерево_0:"<< der0<<std::endl;
  std::cout<<"дерево_1:"<< der1<<std::endl;
  std::cout<<"вызвали конструктор копирования (дерево_2{дерево_1})"<<std::endl;
  std::cout<<"дерево_2:"<< der2<<std::endl;
  der0=der1;
  std::cout<<"после операции дерево_0 = дерево_1:"<<std::endl ;
  std::cout<<"дерево_0:"<< der0<<std::endl;
  std::cout<<"дерево_1:"<< der1<<std::endl;
}
