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
        void addExtraBlack();
        void removeExtraBlack();
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

void RB_BST_Node::addExtraBlack(){
    if(isRed())
        color = 'r';    //red black node
    else
        color = 'b';    //double black node
}

void RB_BST_Node::removeExtraBlack(){
    if(color == 'r')
        color = 'R';
    if(color == 'b')
        color = 'B';
}

bool RB_BST_Node::isRed(){
    return color=='R' || color=='r'/*red black node*/;
}

bool RB_BST_Node::isBlack(){
    return color=='B' || color=='b'/* double black node*/;
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
        RB_BST_Node *nill;
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
        void RightLeftRotate(RB_BST_Node* node);
        void LeftRightRotate(RB_BST_Node* node);
        void CheckColor(RB_BST_Node* node);
        void CorrectTree(RB_BST_Node* node);
        void FixByRotation(RB_BST_Node* node);
        bool isLeaf(RB_BST_Node* node);
        bool hasLeftChild(RB_BST_Node* node);
        bool hasRightChild(RB_BST_Node* node);
        bool isLeftChild(RB_BST_Node* parent,RB_BST_Node* child);
        bool isRightChild(RB_BST_Node* parent,RB_BST_Node* child);
        bool isNull(RB_BST_Node* node);
        RB_BST_Node* Search(int value);
        RB_BST_Node* getRoot();
        RB_BST_Node* getMinimum(RB_BST_Node* node);
        int getMinVal();
        RB_BST_Node* getInorderSuccessor(RB_BST_Node* node);
        void deleteNode(int value);
        void deleteFixup(RB_BST_Node* x);
};

RB_BST::RB_BST(){
    root = NULL;
    nill = new RB_BST_Node();
    nill->setColor('B');
}

RB_BST_Node* RB_BST::getMinimum(RB_BST_Node* node){
    while(!isNull(node->getLeft())){
        node = node->getLeft();
    }
    return node;
}

int RB_BST::getMinVal(){
    return getMinimum(root)->getValue();
}

RB_BST_Node* RB_BST::getInorderSuccessor(RB_BST_Node* node){
    if(!isNull(node->getRight())){
        return getMinimum(node->getRight());
    }
    RB_BST_Node* parent = node->getParent();
    while(!isNull(parent) && isRightChild(parent,node)){
        node = parent;
        parent = parent->getParent();
    }
    return parent;
}

void RB_BST::LeftRotate(RB_BST_Node* node){
    // Left Rotation on a node assumes that its right child is not NULL
    RB_BST_Node* x = node;
    RB_BST_Node* y = node->getRight();
    x->addRight(y->getLeft());
    if(!isNull(y->getLeft()))
        y->getLeft()->setParent(x);
    y->setParent(x->getParent());
    if(isNull(x->getParent()))
        root = y;
    else if(isLeftChild(x->getParent(),x))
        x->getParent()->addLeft(y);
    else
        x->getParent()->addRight(y);
    y->addLeft(x);
    x->setParent(y);
}

void RB_BST::RightRotate(RB_BST_Node* node){
    // Right Rotation on a node assumes that its left child is not NULL
    RB_BST_Node* y = node;
    RB_BST_Node* x = node->getLeft();
    y->addLeft(x->getRight());
    if(!isNull(x->getRight()))
        x->getRight()->setParent(y);
    x->setParent(y->getParent());
    if(isNull(y->getParent()))
        root = x;
    else if(isRightChild(y->getParent(),y))
        y->getParent()->addRight(x);
    else
        y->getParent()->addLeft(x);
    x->addRight(y);
    y->setParent(x);
}

void RB_BST::RightLeftRotate(RB_BST_Node* node){
    RightRotate(node->getRight());
    LeftRotate(node);
}

void RB_BST::LeftRightRotate(RB_BST_Node* node){
    LeftRotate(node->getLeft());
    RightRotate(node);
}

void RB_BST::insert(RB_BST_Node* node){
    if(!node){
        cout << "Node is not initialized" << endl;
        return;
    }
    if(!root){
        root = node;
        root->setParent(nill);
        return;
    }
    RB_BST_Node* temp = root;
    int element = node->getValue();
    while(1){
        if(element <= temp->getValue()){
            if(temp->getLeft() == nill){
                temp->addLeft(node); //if left of node is empty then insert node as left child
                node->setParent(temp);
                break;
            }
            else{
                temp = temp->getLeft();//else go to left branch and continue recursion...
            }
        }
        else{
            if(temp->getRight() == nill){
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
     if (root == nill)
          return;
     /* first recur on left child */
     Inorder(root->getLeft());
 
     /* then print the data of node */
     printf("%d ", root->getValue());  
 
     /* now recur on right child */
     Inorder(root->getRight());
}

void RB_BST::Preorder(RB_BST_Node* root){
     if (root == nill)
          return;

    /* then print the data of node */
     printf("%d ", root->getValue());  

     /* first recur on left child */
     Preorder(root->getLeft());
 
     /* now recur on right child */
     Preorder(root->getRight());
}

void RB_BST::Postorder(RB_BST_Node* root){
     if (root == nill)
          return;
     /* first recur on left child */
     Postorder(root->getLeft());
 
     /* now recur on right child */
     Postorder(root->getRight());

     /* then print the data of node */
     printf("%d ", root->getValue());  
}

RB_BST_Node* RB_BST::Search(int value){
    RB_BST_Node* temp = root;
    while(temp != nill){
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

RB_BST_Node* RB_BST::getRoot(){
    return root;
}

void RB_BST::insertValue(int element){
    RB_BST_Node* node = new RB_BST_Node(element);
    node->addLeft(nill);
    node->addRight(nill);
    RB_BST::insert(node);
    if(node == root){
        root->setColor('B');
        return;
    }
    CheckColor(node);
}

void RB_BST::CheckColor(RB_BST_Node* node){
    if(node == root){
        root->setColor('B');
        return;
    }
    if(node->isRed() && node->getParent()->isRed()){
        CorrectTree(node);
    }
    CheckColor(node->getParent());
}

void RB_BST::CorrectTree(RB_BST_Node* node){
    if(isLeftChild(node->getParent()->getParent(),node->getParent())){
       if(isNull(node->getParent()->getParent()->getRight()) || 
          node->getParent()->getParent()->getRight()->isBlack()) {
            //if uncle is Black then fix by rotation
           FixByRotation(node);
           return;
       }
       //if uncle is Red then fix by recolouring the nodes such that color parent and uncle to Black
       //and color grand parent to Red and check any further violations from grand parent till root
       if(!isNull(node->getParent()->getParent()->getRight())){
           node->getParent()->getParent()->getRight()->setColor('B');
       }
       node->getParent()->getParent()->setColor('R');
       node->getParent()->setColor('B');
       return;
    }
    else{
        //uncle is left child to its parent
        if(isNull(node->getParent()->getParent()->getLeft()) || 
           node->getParent()->getParent()->getLeft()->isBlack()) {
           //if uncle is Black then fix by rotation
           FixByRotation(node);
           return;
       }
       //if uncle is red then fix by recolouring the nodes
       if(!isNull(node->getParent()->getParent()->getLeft())){
           node->getParent()->getParent()->getLeft()->setColor('B');
       }
       node->getParent()->getParent()->setColor('R');
       node->getParent()->setColor('B');
       return;
    }
}

void RB_BST::FixByRotation(RB_BST_Node* node){
    if(isLeftChild(node->getParent(),node)){
        if(isLeftChild(node->getParent()->getParent(),node->getParent())){
            //both node and its parent are left child of their parents
            RightRotate(node->getParent()->getParent());
            node->setColor('R');
            node->getParent()->setColor('B');
            if(!isNull(node->getParent()->getRight()))
                node->getParent()->getRight()->setColor('R');
        }
        else{
            //node is left child but parent is right child
            RightLeftRotate(node->getParent()->getParent());
            node->setColor('B');
            node->getLeft()->setColor('R');
            node->getRight()->setColor('R');
        }
    }
    else{
        if(isRightChild(node->getParent()->getParent(),node->getParent())){
            //both node and parent are right child to their parents
            LeftRotate(node->getParent()->getParent());
            node->setColor('R');
            node->getParent()->setColor('B');
            if(!isNull(node->getParent()->getLeft()))
                node->getParent()->getLeft()->setColor('R');
        }
        else{
            //node is right child and parent is left child
            LeftRightRotate(node->getParent()->getParent());
            node->setColor('B');
            node->getRight()->setColor('R');
            node->getLeft()->setColor('R');
        }
    }
}

bool RB_BST::isLeftChild(RB_BST_Node *parent,RB_BST_Node* child){
    return hasLeftChild(parent) && parent->getLeft() == child;
}

bool RB_BST::isRightChild(RB_BST_Node* parent,RB_BST_Node* child){
    return hasRightChild(parent) && parent->getRight() == child;
}

bool RB_BST::hasLeftChild(RB_BST_Node* node){
    return node->getLeft()!=nill;
}

bool RB_BST::hasRightChild(RB_BST_Node* node){
    return node->getRight()!=nill;
}

bool RB_BST::isLeaf(RB_BST_Node* node){
    return !(hasLeftChild(node) || hasRightChild(node));
}

bool RB_BST::isNull(RB_BST_Node* node){
    return node == nill;
}

void RB_BST::deleteNode(int value){
    RB_BST_Node *z,*y,*x;
    if(isNull(z = Search(value)))
        return;
    if(isNull(z->getLeft()) || isNull(z->getRight()))
        y = z;
    else
        y = getInorderSuccessor(z);
    if(!isNull(y->getLeft()))
        x = y->getLeft();
    else
        x = y->getRight();
    x->setParent(y->getParent());
    if(isNull(y->getParent()))
        root = x;
    else{
        if(isLeftChild(y->getParent(),y))
            y->getParent()->addLeft(x);
        else
            y->getParent()->addRight(x);
    }
    if(y != z)
        z->setValue(y->getValue());
    if(y->isBlack()){
        x->addExtraBlack();
        deleteFixup(x);
    }
}

void RB_BST::deleteFixup(RB_BST_Node* x){
    while(x!=root && x->isBlack()){
        RB_BST_Node* w;
        if(isLeftChild(x->getParent(),x)){
            w = x->getParent()->getRight();
            if(w->isRed()){ //Case 1  x's silbling w is red
                w->setColor('B');
                x->getParent()->setColor('R');
                LeftRotate(x->getParent());
                w = x->getParent()->getRight();
            }
            if(w->getLeft()->isBlack() && w->getRight()->isBlack()){    //Case 2 x's sibling w is black and both of w's children are black
                w->setColor('R');
                x->removeExtraBlack();
                x = x->getParent();
                x->addExtraBlack();
            }
            else{
                if(w->getRight()->isBlack()){   //Case 3  x's sibling w is black and w's left child is red and w's right child is black
                    w->getLeft()->setColor('B');
                    w->setColor('R');
                    RightRotate(w);
                    w = x->getParent()->getRight();
                }
                //Case 4  x's sibling w is black and w's right child is red
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor('B');
                w->getRight()->setColor('B');
                LeftRotate(x->getParent());
                x->removeExtraBlack();
                x = root;
            }
        }
        else{
            w = x->getParent()->getLeft();
            if(w->isRed()){
                w->setColor('B');
                x->getParent()->setColor('R');
                RightRotate(x->getParent());
                w = x->getParent()->getLeft();
            }
            if(w->getRight()->isBlack() && w->getLeft()->isBlack()){
                w->setColor('R');
                x->removeExtraBlack();
                x = x->getParent();
                x->addExtraBlack();
            }
            else{
                if(w->getLeft()->isBlack()){
                    w->getRight()->setColor('B');
                    w->setColor('R');
                    LeftRotate(w);
                    w = x->getParent()->getLeft();
                }
                w->setColor(x->getParent()->getColor());
                x->getParent()->setColor('B');
                w->getRight()->setColor('B');
                RightRotate(x->getParent());
                x->removeExtraBlack();
                x = root;
            }            
        }
    }
    x->setColor('B');
}

int main(int argc, char const *argv[]){
    RB_BST* tree = new RB_BST();
    int keys[8] = {10,5,30,2,7,20,38,35};//{3,1,5,7,6,8,9,10};
    for(int i=0;i<8;i++){
        tree->insertValue(keys[i]);
    }
    tree->printTree(IN_ORDER);
    cout << endl;
    tree->deleteNode(30);
    tree->printTree(IN_ORDER);
    cout << endl;
    for(int i=0;i<8;i++){
        RB_BST_Node* temp = tree->Search(keys[i]);
        if(tree->isNull(temp))
            continue;
        cout << temp->getValue() << " " << temp->getColor() << " " <<
                temp->getLeft()->getValue() << " " << temp->getLeft()->getColor() << " " <<
                temp->getRight()->getValue() << " " << temp->getRight()->getColor() << endl;
    }
    return 0;
}
