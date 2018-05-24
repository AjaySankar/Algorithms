#include<iostream>
using namespace std;
#include "BST_Node.h"
BST_Node::BST_Node(){
    value = INT16_MIN;
    left  = NULL;
    right = NULL;
    parent = NULL;
}

BST_Node::BST_Node(int element){
    value = element;
    left  = NULL;
    right = NULL;
    parent = NULL;
}

void BST_Node::setValue(int element){
    value = element;
}

int BST_Node::getValue(){
    return value;
}

BST_Node* BST_Node::getLeft(){
    return left;
}

BST_Node* BST_Node::getRight(){
    return right;
}

BST_Node* BST_Node::getParent(){
    return parent;
}

void BST_Node::setParent(BST_Node* p){
    parent = p;
}

void BST_Node::addLeft(BST_Node* node){
    left = node;
}

void BST_Node::addRight(BST_Node* node){
    right = node;
}
