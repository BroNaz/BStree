//0,1
#include <iostream>
#include <cstring>//char* strchr(); проверить есть ли в итог реализации 0,1
#include <cstdlib>//int atoi();
#include <string>
#include "tree.hpp"

void show();
void error_input_f();

int main(int argc, char *argv[]) {
    char *locale = setlocale(LC_ALL, "RUS");
    BSTree::Tree tree;
    if( argc <=2 ) {
        if(argc == 2 ) {
            std::string user_line = argv[1];
            tree.insert(atoi(user_line.c_str()));
            for( int i = 0 ; i <user_line.size(); i++) {
                if (user_line[i] == ',')
                    tree.insert(atoi(user_line.substr(i+1).c_str()));
            }
        }
    } else {
        for (int i = 1; i<argc ; i++) {
            tree.insert(atoi(argv[i]));
        }
    }
    bool program_exit = true ;
    while(program_exit) {
        show();
        int show_choice;
        std::cin>>show_choice;
        if(!std::cin) {
            std::cin.clear();
            char ch;
            while(ch!=10) {
                std::cin.get(ch);
                std::cin.clear();
            }
        }
        switch(show_choice) {
        case 1: {
            if (tree.emptiness()) {
                std::cout<<"Дерево пусто";
                break;
            }
            tree.print_graphics();
            break ;
        }
        case 2: {
            if (tree.emptiness()) {
                std::cout<<"Дерево пусто";
                break;
            }
            std::cout<<" a. Прямой обход" <<std::endl
                     <<" b. Поперечный обход" <<std::endl
                     <<" c. Обратный обход "<<std::endl;
            char choice;
            std::cin>>choice;
            switch (choice) {
            case'a': {
                tree.print_order(std::cout,BSTree::traversal_order::pre);
                std::cout<<std::endl;
                break;
            }
            case 'b': {
                tree.print_order(std::cout,BSTree::traversal_order::in);
                std::cout<<std::endl;
                break;
            }
            case'c': {
                tree.print_order(std::cout,BSTree::traversal_order::post);
                std::cout<<std::endl;
                break;
            }
            default: {
                error_input_f();
                break;
            }
            }
            break;
        }
        case 3: {
            if (tree.emptiness()) {
                std::cout<<"Дерево пусто";
                break;
            }
            std::cout<<"введите узел :"<<std::endl;
            int value ;
            std::cin>>value;
            if(!std::cin){
               error_input_f();
            }
            else
            tree.insert(value);
            break;
        }
        case 4: {
          if (tree.emptiness()) {
              std::cout<<"Дерево пусто";
              break;
          }
          std::cout<<"введите узел :"<<std::endl;
          int value ;
          std::cin>>value;
          if(!std::cin){
          error_input_f();
          }
          else
          tree.remove(value);
          break;
        }
        case 5: {
          if (tree.emptiness()) {
              std::cout<<"Дерево пусто";
              break;
          }
          std::cout<<"введите адресс файла:"<<std::endl;
          std::string fail ;
          std::cin>>fail;
          tree.save(fail);
          break;
        }
        case 6: {
            if (tree.emptiness()) {
                std::cout<<"Дерево пусто";
                break;
            }
            std::cout<<"введите адресс файла:"<<std::endl;
            std::string fail ;
            std::cin>>fail;
            tree.load(fail);
            break;
        }
        case 7: {
          if (tree.emptiness()) {
              std::cout<<"Дерево пусто";
              break;
          }
          std::cout<<"введите узел :"<<std::endl;
          int value ;
          std::cin>>value;
          if(!std::cin){
          error_input_f();
          }
          else
          tree.exists(value);
          break;
        }
        case 8: {
            std::cout << "Вы хотите выйти из программы ? (д|н):" << std::endl;
            std::string answer;
            std::cin >> answer;
            if ((answer == "Д") || (answer == "д") || (answer == "да") || (answer == "ДА") || (answer == "Да")) {
                std::cout<<"До свидания !\n";
                program_exit = false ;
            } else if ((answer == "н") || (answer == "нет") || (answer == "Н") || (answer == "НЕТ") || (answer == "Нет")) {
                std::cout << "отмена операции " << std::endl;
            } else {
                std::cout << "команда не распознана " << std::endl;
            }
            std::cin.clear();

            break;
        }
        default: {
            std::cout<<"команда не распознана 🙇"<<std::endl;
            break;
        }
        }
    }
}
void error_input_f(){
std::cout<<"команда не распознана 🙇"<<std::endl;
std::cin.clear();
char ch;
while(ch!=10) {
std::cin.get(ch);
std::cin.clear();}
}

void show() {
    std::cout <<"1. Вывести дерево на экран"<<std::endl<<
              "2. Вывести список узлов дерева "<<std::endl<<
              "3. Добавить узел в дерево "<<std::endl<<
              "4. Удалить узел из дерева "<<std::endl<<
              "5. Сохранить дерево в файл "<<std::endl<<
              "6. Загрузить дерево из файла "<<std::endl<<
              "7. Проверить наличие узла "<<std::endl<<
              "8. Завершить работу программы"<<std::endl;
}
