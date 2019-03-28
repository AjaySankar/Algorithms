#include "AVL_Node.h"

AVL_Node::AVL_Node(){
    value = INT16_MIN;
    left  = NULL;
    right = NULL;
    parent = NULL;
    height = 0;
}

AVL_Node::AVL_Node(int element){
    value = element;
    left  = NULL;
    right = NULL;
    parent = NULL;
    height = 0;
}

void AVL_Node::setValue(int element){
    value = element;
}

int AVL_Node::getValue(){
    return value;
}

AVL_Node* AVL_Node::getLeft(){
    return left;
}

AVL_Node* AVL_Node::getRight(){
    return right;
}

AVL_Node* AVL_Node::getParent(){
    return parent;
}

void AVL_Node::setParent(AVL_Node* p){
    parent = p;
}

void AVL_Node::addLeft(AVL_Node* node){
    left = node;
}

void AVL_Node::addRight(AVL_Node* node){
    right = node;
}

int AVL_Node::getHeight() {
    return height;
}

void AVL_Node::setHeight() {
    int leftHeight = this->left ? this->left->height : 0;
    int rightHeight = this->right ? this->right->height : 0;
    this->height = leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}