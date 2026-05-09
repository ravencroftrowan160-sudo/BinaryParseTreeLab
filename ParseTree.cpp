#include "ParseTree.hpp"

void ParseTree::destroy(Node* n){
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
    if(!n) return "";

    return std::string(1, n->value) + preOrder(n->leftc) + preOrder(n->rightc);
}

std::string ParseTree::inOrder(Node* n){
    if(!n) return "";
    return "(" + inOrder(n->leftc) + std::string(1, n->value) + inOrder(n->rightc) + ")";
}

std::string ParseTree::postOrder(Node* n){
    if(!n) return "";

    return postOrder(n->leftc) + postOrder(n->rightc) + std::string(1, n->value);
}

ParseTree::ParseTree(const std::string& expr){
    if(expr.empty()){
        root = nullptr;
        return;
    }

    std::stack<Node*> st;

    for (char c : expr) {
        if (isalpha(c)) {
            st.push(new Node(c));
        } 
        else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* op = new Node(c);
            op->leftc = left;
            op->rightc = right;

            st.push(op);
        }
    }

    root = st.top();   // ← only here
}
    
ParseTree::~ParseTree(){
    if(!root) return;

    destroy(root);
}

std::string ParseTree::preOrder(){
    return preOrder(root);
}

std::string ParseTree::inOrder(){
    return inOrder(root);
}

std::string ParseTree::postOrder(){
    return postOrder(root);
}

void ParseTree::display(){
        const int PAGE_WIDE = 64;
    Node* dummy = nullptr;
    std::string emptyNode = ".";
    std::stringstream buffer;
    std::queue<Node*> theQueue;

    if (!root) {
        return "[empty tree]";
    }

    theQueue.push(root);
    int curNodes = 1;
    bool more = true;

    while (more)
    {
        more = false;
        int offset = PAGE_WIDE / (curNodes * 2);

        for (int i = 0; i < curNodes; i++)
        {
            Node* ptr = theQueue.front();
            theQueue.pop();

            if (i == 1)
                offset *= 2;

            if (ptr != dummy)
            {
                buffer << std::setw(offset) << ptr->value;

                if (ptr->leftc) {
                    more = true;
                    theQueue.push(ptr->leftc);
                } else {
                    theQueue.push(dummy);
                }

                if (ptr->rightc) {
                    more = true;
                    theQueue.push(ptr->rightc);
                } else {
                    theQueue.push(dummy);
                }
            }
            else
            {
                buffer << std::setw(offset) << emptyNode;
                theQueue.push(dummy);
                theQueue.push(dummy);
            }
        }

        buffer << "\n";
        curNodes *= 2;
    }

    return buffer.str();
}