#include <initializer_list>
#include "tree.hpp"
//#include <cstring>
#include <sstream>

BSTree::Tree::Tree(std::initializer_list<int> list) {
    for(auto& item : list)
        insert(item);
}

auto BSTree::Tree::swap(Tree& tree)-> void{
    std::swap(root, tree.root);
}

BSTree::Tree::Tree(const Tree& tree) {
    root = nullptr;
    std::string str;
    std::stringstream out(str);
    out << tree;
    int value;
    while(out) {
        out >> value;
        this->insert(value);
    }
}

auto BSTree::Tree::operator=(const BSTree::Tree& tree) -> Tree& {
    destructor(root);
    Tree tmp{tree};
    this->swap(tmp);
    return *this;
}

bool BSTree::Tree::insert(int value) {
    if (root == nullptr) {
        root = new Node {value};
        return true;
    } else {
        if (exists(value)) {
            return false;
        }
        Node* node = root ;
        while (node != nullptr) {
            if(node->data > value) {
                if(node->left == nullptr) {
                    node ->left = new Node{value};
                    return true;
                }
                node = node->left ;
            }
            if(node->data < value) {
                if(node->right == nullptr) {
                    node ->right = new Node{value};
                    return true;
                }
                node = node->right ;
            }
        }
    }
}
bool BSTree::Tree::emptiness()const {
    if (root == nullptr)
        return true;
    else  return false ;
}

bool BSTree::Tree::exists(int value) const  {
    if (this->emptiness())
        return false ;
    Node* relevance = root ;
    while (relevance != nullptr) {
        if(relevance->data  == value)
            return true ;
        if(relevance->data > value) {
            relevance = relevance->left;
        } else {
            relevance = relevance->right;
        }
    }
    return false ;
}
/*
void treeprint_pre(BSTree::Node *tree) {
    if (tree!=nullptr) {
        std::cout << tree->data<<"  ";
        treeprint_pre(tree->left);
        treeprint_pre(tree->right);
    }
}
void treeprint_in(BSTree::Node *tree) {
    if (tree!=nullptr) {
        treeprint_in(tree->left);
        std::cout << tree->data<<"  ";
        treeprint_in(tree->right);
    }
}
void treeprint_post(BSTree::Node *tree) {
    if (tree!=nullptr) {
        treeprint_post(tree->left);
        treeprint_post(tree->right);
        std::cout << tree->data<<"  ";
    }
}
*/

auto print_pre(std::ostream& out, const BSTree::Node* node) -> std::ostream& {
    if(node != nullptr) {
        out << node->data<<"  ";
        print_pre(out, node->left);
        print_pre(out, node->right);
    }
    return out;
}

auto print_in(std::ostream& out, const BSTree::Node* node)-> std::ostream& {
    if(node != nullptr) {
        print_in(out,node->left);
        out << node->data<<"  ";
        print_in(out,node->right);
    }
    return out;
}

auto print_post(std::ostream& out, const BSTree::Node* node)  -> std::ostream& {
    if(node != nullptr) {
        print_post(out,node->left);
        print_post(out,node->right);
        out << node->data<<"  ";
    }
    return out;
}

auto BSTree::Tree::print_order(std::ostream& out, BSTree::traversal_order order) const  -> std::ostream& {
    if(order == traversal_order::pre) {
        print_pre(out,root);
    } else if (order == traversal_order::in) {
        print_in(out,root);
    } else {
        print_post(out,root);
    }
    return out;
}

void BSTree::Tree::print_graphics_access_to_root(Node* node)const {
    if (root == nullptr) {
        std::cout << "Дерево пусто!" << std::endl;
    }
    if (node != nullptr) {
        static int count_rec = 0;
        if (node == root) {
            print_graphics_access_to_root(node->right);
            std::cout << std::endl <<node->data<< std::endl << std::endl;
            print_graphics_access_to_root(node->left);
            return;
        }
        count_rec++;
        print_graphics_access_to_root(node->right);
        for (int i = 0; i < count_rec; i++)  std::cout << "    ";
        std::cout << "~ "<<node->data<<std::endl;
        print_graphics_access_to_root(node->left);
        count_rec--;
        return;
    }
}

void BSTree::Tree::print_graphics()const {
    if(root == nullptr) {
        std::cout <<"Дерево пусто!" <<std::endl;
        return;
    }
    this->print_graphics_access_to_root(root);
    return ;
}

void BSTree::Tree::destructor(Node* node) {
    if(node != nullptr) {
        destructor(node->left);
        destructor(node->right);
        //std::cout<<"удален лист со значением:"<<node->data<<std::endl;
        delete node ;
    }
}

/*
auto BSTree::Tree::remove(int value)-> bool{
    if(!exists(value))
        {return false;}
    Node* pointer = root;
    Node* parent  = nullptr;
    while(pointer->data != value) {
        parent = pointer;
        if(value < pointer->data)
            pointer = pointer->left;
        else
            pointer = pointer->right;
    }
    Node* removed = nullptr;
    if (pointer->left == nullptr || pointer->right == nullptr) {
        Node* child = nullptr;
        removed = pointer;

        if(pointer->left != nullptr)
            child = pointer->left;
        else if(pointer->right != nullptr)
            child = pointer->right;

        if(parent == nullptr)
            root = child;
        else {
            if(parent->left == pointer)
                parent->left = child;
            else
                parent->right = child;
        }
    } else {
        Node* mostLeft = pointer->right;
        Node* mostLeftParent = pointer;

        while (mostLeft->left != nullptr) {
            mostLeftParent = mostLeft;
            mostLeft = mostLeft->left;
        }

        pointer->data = mostLeft->data;
        removed = mostLeft;

        if(mostLeftParent->left == mostLeft)
            mostLeftParent->left = nullptr;
        else
            mostLeftParent->right = mostLeft->right;
    }
    delete removed;
    removed = nullptr;
    return true;
}*/
auto BSTree::Tree::remove(int value)-> bool{
    if(!exists(value)) {
        return false;
    }
    Node* ptr = root;
    Node* parent = nullptr;
    while(ptr->data != value) {
        parent = ptr;
        if(value < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    Node* removed = nullptr;
    if (ptr->left == nullptr || ptr->right == nullptr) {
        Node* heir = nullptr; // наследник
        removed = ptr;

        if(ptr->left != nullptr)
            heir = ptr->left;
        else if(ptr->right != nullptr)
            heir = ptr->right;

        if(parent == nullptr)
            root = heir;
        else {
            if(parent->left == ptr)
                parent->left = heir;
            else
                parent->right = heir;
        }
    } else {
        Node* left_ = ptr->right;
        Node* Left_Parent = ptr;

        while (left_->left != nullptr) {
            Left_Parent = left_;
            left_ = left_->left;
        }

        ptr->data = left_->data;
        removed = left_;

        if(Left_Parent->left == left_)
            Left_Parent->left = nullptr;
        else
            Left_Parent->right = left_->right;
    }
    delete removed;
    removed = nullptr;
    return true;
}


bool BSTree::Tree::save(const std::string& path)const {
    std::ifstream file_in(path.c_str());
    if(!file_in.is_open()) {
        std::ofstream file_out(path.c_str());
        file_out<< *this ;
        file_out.close();
        return true ;
    } else {
        bool error_input= true;
        while(error_input) {
            std::string answer;
            std::cout<<"перезаписать файл ? д/н"<<std::endl ;
            std::cin>>answer ; 
            if ((answer == "Д") || (answer == "д") || (answer == "да") || (answer == "ДА") || (answer == "Да")) {
                std::ofstream file_out(path.c_str());
                file_out<< *this ;
                file_out.close();
                std::cout<<"файл : "<<path<<" перезаписан !"<<std::endl;
                return true;
            } else if ((answer == "н") || (answer == "нет") || (answer == "Н") || (answer == "НЕТ") || (answer == "Нет")) {
                std::cout << "отмена операции " << std::endl;
                return false ;
            } else {
                std::cout << "команда не распознана " << std::endl;
                std::cout << "попробуйте ввести ещё раз"<<std::endl;
            }
        }
    }
}

bool BSTree::Tree::load(const std::string& path) {
    std::ifstream file_in(path.c_str());
    if(!file_in.is_open()) {
        return false ;
    }
    destructor(root);
    int in ;
    file_in>>in;
    if(!file_in)
        return false ;
    while (file_in) {
        insert(in);
        file_in>>in;
    }
    return true ;
}
