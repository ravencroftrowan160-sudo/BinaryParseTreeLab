
#ifndef PARSETREE_HPP
#define PARSETREE_HPP

#include <stdexcept> //for exceptions
#include <string>

struct Node{
    char value;
    Node* leftc;
    Node* rightc;
};

class ParseTree{
private:
    Node* root;

    void destroy(Node* n);
    std::string preOrder(Node* n);
    std::string inOrder(Node* n);
    std::string postOrder(Node* n);   
public:
    ParseTree(const std::string& expr);
    ~ParseTree();

    std::string preOrder();
    std::string inOrder();
    std::string postOrder();
    void display();
};
#endif