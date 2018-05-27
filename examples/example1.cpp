#include <iostream>
#include <cstring>//char* strchr(); проверить есть ли в итог реализации 0,1
#include <cstdlib>//int atoi();
#include <string>
#include "tree.hpp"

using namespace BSTree;

int main(){
  Tree der0;
  std::cout<<"было созданно 1 дерева без каких либо узлов"<<der0<<std::endl ;
  std::cout<<"добавим через метот insert 3 узла:"<<std::endl;
  der0.insert(52);
  der0.insert(-40000);
  der0.insert(1234567);
  std::cout<<"дерево стало :"<< der0<<std::endl;
  std::cout<<"удалим 1 элемент по средствам метода remove"<<std::endl;
  der0.remove(52);
  std::cout<<"после операции дерево:"<<std::endl ;
  std::cout<< der0<<std::endl;
}
