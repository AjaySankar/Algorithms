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
    X->height = 1+std::max(getHeight(X->right), getHeight(X->left));
    Y->height = 1+std::max(getHeight(Y->right), X->height);
    return Y;
}

int AVL::getHeight(AVL_Node* node) {
    if(!node)
        return -1;
    return node->height;
}

AVL_Node* AVL::rightRotate(AVL_Node* root) {
    AVL_Node* X = root; AVL_Node* Y = X->left;
    X->left = Y->right;
    Y->right = X;
    X->height = 1+std::max(getHeight(X->right), getHeight(X->left));
    Y->height = 1+std::max(getHeight(Y->left), X->height);
    return Y;
}

AVL_Node* AVL::leftRightRotate(AVL_Node* root) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
}

AVL_Node* AVL::rightLeftRotate(AVL_Node* root) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
}

AVL_Node* AVL::insert(AVL_Node* node, int value) {
    if(!node) {
        node = new AVL_Node(value);
    }
    else if (node->getValue() < value) {
        node->right = insert(node->right, value);
        if(getHeight(node->right) - getHeight(node->left) == 2) {
            if(root->right->value > value) {
                node = rightLeftRotate(node);
            }
            else {
                node = leftRotate(node);
            } 
        }
    }
    else if(node->getValue() > value){
        node->left = insert(node->left, value);
        if(getHeight(node->left) - getHeight(node->right) == 2) {
            if(root->left->value < value) {
                node = leftRightRotate(node);
            }
            else {
                node = rightRotate(node);
            }
        }
    }
    node->height = 1+std::max(getHeight(node->left), getHeight(node->right));
    return node;
}

int main() { 
    AVL* tree = new AVL();
    tree->root = tree->insert(tree->root,15);
    tree->root = tree->insert(tree->root,6);
    tree->root = tree->insert(tree->root,18);
    tree->root = tree->insert(tree->root,3);
    tree->root = tree->insert(tree->root,7);
    tree->root = tree->insert(tree->root,17);
    tree->root = tree->insert(tree->root,20);
    tree->root = tree->insert(tree->root,2);
    tree->root = tree->insert(tree->root,4);
    tree->root = tree->insert(tree->root,13);
    tree->root = tree->insert(tree->root,9);
    tree->printTree(IN_ORDER);
    return 0;
}