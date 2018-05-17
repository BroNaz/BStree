#pragma once
#include <fstream>
#include <string>
#include <iostream>
namespace BSTree {
struct Node {
    int   data ;
    Node* left = nullptr;
    Node* right = nullptr;
};


enum class traversal_order {pre, in, post};

class Tree {
private:
    Node* root;
    void destructor(Node*);
    void print_graphics_access_to_root(Node*)const ;
public:
    Tree() {
        root = nullptr;
    };
    Tree(std::initializer_list<int> list);
    Tree(const Tree& tree);
    bool insert(int);
    bool emptiness()const;
    bool exists(int value)const;
    auto remove(int value)->bool;
    bool save(const std::string& path)const;
    bool load(const std::string& path);
    auto print_order(std::ostream& out, BSTree::traversal_order order) const  -> std::ostream&;
    void print_graphics()const;
    auto friend operator<<(std::ostream& stream, const Tree& tree) -> std::ostream& {
        return tree.print_order(stream, BSTree::traversal_order::pre);
    }
    auto operator=(const Tree&) -> Tree&;
    auto swap(Tree& tree) -> void;
    ~Tree() {
        destructor(root);
    };
};
}
