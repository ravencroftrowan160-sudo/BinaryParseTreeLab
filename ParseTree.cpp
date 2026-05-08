    #include "ParseTree.hpp"

    ParseTree::destroy(Node* n){
        if(!n){
            //can be shortened to if(!n) return; but I like this better(it's neater but more lines)
            return;
        }

        //recurse to left child if left child isn't null
        destroy(n->leftc);

        //recurse to right child
        destroy(n->rightc);

        delete n;
    }

    std::string ParseTree::preOrder(Node* n){

    }

    ParseTree::ParseTree() : arg(""), root(nullptr){

    }
    
    ParseTree::~ParseTree(){
        if(!root) return;

        destroy(root);

    }

    std::string preOrder(){

    }

    std::string inOrder(){

    }

    std::string postOrder(){

    }

    void display(){

    }