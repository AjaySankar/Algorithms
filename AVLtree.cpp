#include "AVLtree.h"

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
     cout << root->getValue() << " : " << root->getHeight() << endl;
 
     /* now recur on right child */
     Inorder(root->getRight());
}

AVL_Node* AVL::leftRotate(AVL_Node* root) {
    AVL_Node* X = root; AVL_Node* Y = X->right;
    X->right = Y->left;
    Y->left = X;
    X->height = std::max(X->left ? X->left->height : 0, X->right ? X->right->height : 0);
    return Y;
}

AVL_Node* AVL::rightRotate(AVL_Node* root) {
    AVL_Node* X = root; AVL_Node* Y = X->left;
    X->left = Y->right;
    Y->right = X;
    X->height = std::max(X->left ? X->left->height : 0, X->right ? X->right->height : 0);
    return Y;
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
    node->setHeight();
    return node;
}

int main() { 
    AVL* tree = new AVL();
    tree->insert(tree->root,3);
    tree->insert(tree->root,2);
    tree->insert(tree->root,1);
    AVL_Node* newRoot = tree->rightRotate(tree->root);
    //cout << newRoot->getValue() << " " << newRoot->getLeft()->getValue() << " " << newRoot->getRight()->getValue();
    //tree->Inorder(newRoot);
    /*tree->insert(tree->root,3);
    tree->insert(tree->root,7);
    tree->insert(tree->root,17);
    tree->insert(tree->root,20);
    tree->insert(tree->root,2);
    tree->insert(tree->root,4);
    tree->insert(tree->root,13);
    tree->insert(tree->root,9);*/
    AVL* newTree = new AVL(newRoot);
    newTree->printTree(IN_ORDER);
    return 0;
}