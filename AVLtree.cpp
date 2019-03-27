#include<iostream>
#include<algorithm>
using namespace std;
#include "AVLtree.h"
#include "stdio.h"

AVL::AVL(){
    root = NULL;
}

AVL::AVL(AVL_Node* node){   //Need to implement copy constructor this is just shallow copy so donot edit
                            //the output tree of ths constructor (Read only)
    root = node;
}

AVL_Node* AVL::getRoot(){
    return root;
}

void AVL::printTree(Traversal_Type type){
    switch(type){
        case IN_ORDER:
            Inorder(root);
            break;
        default:
            cout << "Invalid type" << endl;
            break;
    }
}

void AVL::Inorder(AVL_Node* root){
     if (root == NULL)
          return;
     /* first recur on left child */
     Inorder(root->getLeft());
 
     /* then print the data of node */
     printf("%d ", root->getValue());  
 
     /* now recur on right child */
     Inorder(root->getRight());
}

AVL_Node* AVL::insert(AVL_Node* node, int value) {
    if(!node) {
        AVL_Node* newNode = new AVL_Node(value);
        if(!this->root)
            this->root = newNode;
        return newNode;
    }
    else if (node->getValue() < value) {
        node->right = insert(node->right, value);
    }
    else{
        node->left = insert(node->left, value);
    }
    return node;
}

int main() { 
    AVL* tree = new AVL();
    tree->insert(tree->root,15);
    tree->insert(tree->root,6);
    tree->insert(tree->root,18);
    tree->insert(tree->root,3);
    tree->insert(tree->root,7);
    tree->insert(tree->root,17);
    tree->insert(tree->root,20);
    tree->insert(tree->root,2);
    tree->insert(tree->root,4);
    tree->insert(tree->root,13);
    tree->insert(tree->root,9);
    tree->printTree(IN_ORDER);
    return 0;
}