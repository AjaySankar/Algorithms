#include<iostream>
using namespace std;

class RB_BST_Node : public BST_Node{
    private:
        char color;
    
    public:
        RB_BST_Node();
        explicit RB_BST_Node(int element,char c);
        char getColor();
        void setColor(char c);
        bool isRed();
        bool isBlack();
};

RB_BST_Node::RB_BST_Node(){
    color = 'R';
}

RB_BST_Node::RB_BST_Node(int element) : BST_Node(element){
    this();
}

char RB_BST_Node::getColor(){
    return color;
}

void RB_BST_Node::setColor(char c){
    if(c == 'R' || c=='B'){
        color = c;
        return;
    }
    cout << "Invalid color" << endl;
    return;
}

bool RB_BST_Node::isRed(){
    return color=='R';
}

bool RB_BST_Node::isBlack(){
    return color=='B';
}

class RB_BST : public BST{
    public:
        RB_BST();
        RB_BST(RB_BST_Node* node);
        void LeftRotate(RB_BST_Node* node);
        void RightRotate(RB_BST_Node* node);
        void insert(int element,char c);
        void RB_BST_Fixup(RB_BST_Node* node);
};

void RB_BST::LeftRotate(RB_BST_Node* node){

}

void RB_BST::RightRotate(RB_BST_Node* node){

}

void RB_BST::insert(int element){
    RB_BST_Node* node = new RB_BST_Node(element);
    BST::insert(node);
    if(node == root){
        root->setColor('B');
        return;
    }
    RB_BST_Fixup(node);
}

void RB_BST::RB_BST_Fixup(RB_BST_Node* node){

}