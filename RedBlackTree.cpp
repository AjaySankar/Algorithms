#include<iostream>
#include<bits/stdc++.h>
using namespace std;
enum Traversal_Type{PRE_ORDER=1,IN_ORDER,POST_ORDER};

class RB_BST_Node{
    private:
        char color;
        int value;
        RB_BST_Node* left;
        RB_BST_Node* right;
        RB_BST_Node* parent;
    
    public:
        RB_BST_Node();
        explicit RB_BST_Node(int element);
        int getValue();
        void setValue(int element);
        RB_BST_Node* getLeft();
        RB_BST_Node* getRight();
        RB_BST_Node* getParent();
        void setParent(RB_BST_Node* node);
        void addLeft(RB_BST_Node* node);
        void addRight(RB_BST_Node* node);
        char getColor();
        void setColor(char c);
        bool isRed();
        bool isBlack();
};

RB_BST_Node::RB_BST_Node(){
    value = INT16_MIN;
    left  = NULL;
    right = NULL;
    parent = NULL;
    color = 'R';
}

RB_BST_Node::RB_BST_Node(int element){
    value = element;
    left  = NULL;
    right = NULL;
    parent = NULL;
    color = 'R';
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

void RB_BST_Node::setValue(int element){
    value = element;
}

int RB_BST_Node::getValue(){
    return value;
}

RB_BST_Node* RB_BST_Node::getLeft(){
    return left;
}

RB_BST_Node* RB_BST_Node::getRight(){
    return right;
}

RB_BST_Node* RB_BST_Node::getParent(){
    return parent;
}

void RB_BST_Node::setParent(RB_BST_Node* p){
    parent = p;
}

void RB_BST_Node::addLeft(RB_BST_Node* node){
    left = node;
}

void RB_BST_Node::addRight(RB_BST_Node* node){
    right = node;
}

class RB_BST{
    private:
        RB_BST_Node *root;
    public:
        RB_BST();
        RB_BST(RB_BST_Node* node);
        void insert(RB_BST_Node* node);
        void insertValue(int element);
        void printTree(Traversal_Type type);
        void Inorder(RB_BST_Node* root);
        void Preorder(RB_BST_Node* root);
        void Postorder(RB_BST_Node* root);
        void LeftRotate(RB_BST_Node* node);
        void RightRotate(RB_BST_Node* node);
        void RB_BST_Fixup(RB_BST_Node* node);
};

RB_BST::RB_BST(){
    root = NULL;
}

void RB_BST::LeftRotate(RB_BST_Node* node){

}

void RB_BST::RightRotate(RB_BST_Node* node){

}

void RB_BST::insert(RB_BST_Node* node){
    if(!node){
        cout << "Node is not initialized" << endl;
        return;
    }
    if(!root){
        root = node;
        return;
    }
    RB_BST_Node* temp = root;
    int element = node->getValue();
    while(1){
        if(element <= temp->getValue()){
            if(temp->getLeft() == NULL){
                temp->addLeft(node); //if left of node is empty then insert node as left child
                node->setParent(temp);
                break;
            }
            else{
                temp = temp->getLeft();//else go to left branch and continue recursion...
            }
        }
        else{
            if(temp->getRight() == NULL){
                temp->addRight(node);//if right of node is empty then insert node as right child
                node->setParent(temp);
                break;
            }
            else{
                temp = temp->getRight();//else go to right branch and continue the recursion...
            }
        }
    }
    return;
}

void RB_BST::printTree(Traversal_Type type){
    switch(type){
        case IN_ORDER:
            Inorder(root);
            break;
        case PRE_ORDER:
            Preorder(root);
            break;
        case POST_ORDER:
            Postorder(root);
            break;
        default:
            cout << "Invalid type" << endl;
            break;
    }
}

void RB_BST::Inorder(RB_BST_Node* root){
     if (root == NULL)
          return;
     /* first recur on left child */
     Inorder(root->getLeft());
 
     /* then print the data of node */
     printf("%d ", root->getValue());  
 
     /* now recur on right child */
     Inorder(root->getRight());
}

void RB_BST::Preorder(RB_BST_Node* root){
     if (root == NULL)
          return;

    /* then print the data of node */
     printf("%d ", root->getValue());  

     /* first recur on left child */
     Preorder(root->getLeft());
 
     /* now recur on right child */
     Preorder(root->getRight());
}

void RB_BST::Postorder(RB_BST_Node* root){
     if (root == NULL)
          return;
     /* first recur on left child */
     Postorder(root->getLeft());
 
     /* now recur on right child */
     Postorder(root->getRight());

     /* then print the data of node */
     printf("%d ", root->getValue());  
}

void RB_BST::insertValue(int element){
    RB_BST_Node* node = new RB_BST_Node(element);
    RB_BST::insert(node);
    if(node == root){
        root->setColor('B');
        return;
    }
    RB_BST_Fixup(node);
}

void RB_BST::RB_BST_Fixup(RB_BST_Node* node){

}

int main(int argc, char const *argv[]){
    RB_BST* tree = new RB_BST();
    int keys[14] = {7,4,11,3,6,9,18,2,14,19,12,17,22,20};
    for(int i=0;i<14;i++){
        tree->insertValue(keys[i]);
    }
    tree->printTree(IN_ORDER);
    return 0;
}
