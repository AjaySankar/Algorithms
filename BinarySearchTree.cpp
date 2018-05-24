#include<iostream>
using namespace std;
#include "BST.h"

BST::BST(){
    root = NULL;
}

BST::BST(BST_Node* node){   //Need to implement copy constructor this is just shallow copy so donot edit
                            //the output tree of ths constructor (Read only)
    root = node;
}

void BST::insert(BST_Node* node){
    if(!node){
        cout << "Node is not initialized" << endl;
        return;
    }
    if(!root){
        root = node;
        return;
    }
    BST_Node* temp = root;
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

void BST::insertValue(int element){
    insert(new BST_Node(element));
}

BST_Node* BST::getMinimum(){
    BST_Node* temp = root;
    while(temp->getLeft()){
        temp = temp->getLeft();
    }
    return temp;
}

BST_Node* BST::getMaximum(){
    BST_Node* temp = root;
    while(temp->getRight()){
        temp = temp->getRight();
    }
    return temp;
}

BST_Node* BST::getRoot(){
    return root;
}

BST_Node* BST::Search(int value){
    BST_Node* temp = root;
    while(temp){
        if(temp->getValue() < value){
            temp = temp->getRight();
        }
        else if (temp->getValue() > value)
        {   
            temp = temp->getLeft();
        }
        else{
            break;
        }
    }
    return temp;
}

BST_Node* BST::SearchForParent(int value){
    if(root->getValue() == value){
        return (BST_Node*)NULL;
    }
    BST_Node* temp   = root;
    BST_Node* parent = new BST_Node();
    while(temp){
        if(temp->getValue() < value){
            parent = temp;
            temp = temp->getRight();
        }
        else if (temp->getValue() > value)
        {   
            parent = temp;
            temp = temp->getLeft();
        }
        else{
            break;
        }
    }
    return parent;
}

bool BST::hasLeftChild(BST_Node* node){
    return node->getLeft()!=NULL;
}

bool BST::hasRightChild(BST_Node* node){
    return node->getRight()!=NULL;
}

bool BST::isLeaf(BST_Node* node){
    return !(hasLeftChild(node) || hasRightChild(node));
}

bool BST::isLeftChild(BST_Node *parent,BST_Node* child){
    return hasLeftChild(parent) && parent->getLeft() == child;
}

bool BST::isRightChild(BST_Node* parent,BST_Node* child){
    return hasRightChild(parent) && parent->getRight() == child;
}

void BST::deleteNode(int element){
    BST_Node* node = new BST_Node();
    if((node = Search(element)) == NULL){
        cout << "Element to be deleted not found" << endl;
        return;
    }
    if(isLeaf(root)){ //handle the case where only root is in the tree with no children
        //free root;
        return;
    }
    BST_Node* parent = SearchForParent(element);
    if(isLeaf(node)){  //leaf node
        if(hasLeftChild(parent) && parent->getLeft()->getValue() == element)
            parent->addLeft(NULL);
        else
            parent->addRight(NULL); 
        //free node
        return;
    }
    if(hasLeftChild(node) && !hasRightChild(node)){ //node with only left child
        if(!parent){    //handle case where root has to be deleted
            BST_Node* temp = root;
            root = root->getLeft();
            //free temp
            return;
        }
        isLeftChild(parent,node) ? parent->addLeft(node->getLeft()) 
                                 : parent->addRight(node->getLeft());
        //free node
        return;
    }
    if(hasRightChild(node) && !hasLeftChild(node)){ //node with only right child
        if(!parent){    //handle case where root has to be deleted
            BST_Node* temp = root;
            root = root->getRight();
            //free temp
            return;
        }
        isLeftChild(parent,node) ? parent->addLeft(node->getRight()) 
                                 : parent->addRight(node->getRight());
        //free node
        return;
    }
    //node to be deleted has two children
    BST_Node* inorder_sucr = getInorderSuccessor(element);
    BST_Node* parent_inorder_sucr = SearchForParent(inorder_sucr->getValue());
    node->setValue(inorder_sucr->getValue());
    if(isRightChild(node,inorder_sucr)){  //check if inorder successor is immediate right child of node to be deleted
        node->addRight(inorder_sucr->getRight()); //just replace the inorder successor with it's right child
        //free inorder_sucr;
        return;
    }
    parent_inorder_sucr->addLeft(inorder_sucr->getRight()); //if inorder successor is in right subtree then replace it with its right child
    //free inorder_scr;
    return;
}

BST_Node* BST::getInorderSuccessor(int value){
    BST_Node* val  = Search(value);
    BST_Node* succ = new BST_Node();
    if(val){
        if(val->getRight()){
            BST* subtree = new BST(val->getRight());
            succ = subtree->getMinimum();
        }
        else{
            BST_Node* temp = root;
            while(temp){
                if(temp->getValue() > value){
                    succ = temp;
                    temp = temp->getLeft();
                }
                else if (temp->getValue() < value){
                    temp = temp->getRight();
                }   
                else
                    break;
            }
        }
    }
    return succ;
}

void BST::printTree(Traversal_Type type){
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

void BST::Inorder(BST_Node* root){
     if (root == NULL)
          return;
     /* first recur on left child */
     Inorder(root->getLeft());
 
     /* then print the data of node */
     printf("%d ", root->getValue());  
 
     /* now recur on right child */
     Inorder(root->getRight());
}

void BST::Preorder(BST_Node* root){
     if (root == NULL)
          return;

    /* then print the data of node */
     printf("%d ", root->getValue());  

     /* first recur on left child */
     Preorder(root->getLeft());
 
     /* now recur on right child */
     Preorder(root->getRight());
}

void BST::Postorder(BST_Node* root){
     if (root == NULL)
          return;
     /* first recur on left child */
     Postorder(root->getLeft());
 
     /* now recur on right child */
     Postorder(root->getRight());

     /* then print the data of node */
     printf("%d ", root->getValue());  
}

int main(){
    BST *tree = new BST();
    tree->insertValue(15);
    tree->insertValue(6);
    tree->insertValue(18);
    tree->insertValue(3);
    tree->insertValue(7);
    tree->insertValue(17);
    tree->insertValue(20);
    tree->insertValue(2);
    tree->insertValue(4);
    tree->insertValue(13);
    tree->insertValue(9);
    tree->printTree(IN_ORDER);   cout << endl;
    tree->deleteNode(15);
    tree->printTree(IN_ORDER);   cout << endl;
    return 0;
}