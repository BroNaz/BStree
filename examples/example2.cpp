#include <iostream>
#include <cstring>//char* strchr(); проверить есть ли в итог реализации 0,1
#include <cstdlib>//int atoi();
#include <string>
#include "tree.hpp"

using namespace BSTree;

int main(){
  Tree tree{1,2,75,85,95,15,25,35,45,65};
  Tree treenew{1,7};
  std::cout<<"первое дерево "<<tree<<std::endl;
  std::cout<<"второе дерево "<<treenew<<std::endl<<"сохраним 1 дерево в фаил и из него запишим значение во 2 дерево"<<std::endl;
  std::cout<<"введите адресс файла:"<<std::endl;
  std::string fail ;
  std::cin>>fail;
  tree.save(fail);
  treenew.load(fail);
  std::cout<<treenew;
}
