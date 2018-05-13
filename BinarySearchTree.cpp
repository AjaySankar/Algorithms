#include<iostream>
using namespace std;
enum Traversal_Type{PRE_ORDER=1,IN_ORDER,POST_ORDER};

class BST_Node{
    private:
        int value;
        BST_Node* left;
        BST_Node* right;
    public:
        BST_Node();
        explicit BST_Node(int element);
        int getValue();
        void setValue(int element);
        BST_Node* getLeft();
        BST_Node* getRight();
        void addLeft(BST_Node* node);
        void addRight(BST_Node* node);
};

BST_Node::BST_Node(){
    value = INT16_MIN;
    left  = NULL;
    right = NULL;
}

BST_Node::BST_Node(int element){
    value = element;
    left  = NULL;
    right = NULL;
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

void BST_Node::addLeft(BST_Node* node){
    left = node;
}

void BST_Node::addRight(BST_Node* node){
    right = node;
}

class BST{
    private:
        BST_Node* root;
    public:
        BST();
        void insert(int element);
        void printTree(Traversal_Type type);
        void Inorder(BST_Node* root);
        void Preorder(BST_Node* root);
        void Postorder(BST_Node* root);
};

BST::BST(){
    root = NULL;
}

void BST::insert(int element){
    if(!root){
        root = new BST_Node(element);
        return;
    }
    BST_Node* temp = root;
    BST_Node* newNode = new BST_Node(element);
    while(1){
        if(element <= temp->getValue()){
            if(temp->getLeft() == NULL){
                temp->addLeft(newNode); //if left of node is empty then insert node as left child
                break;
            }
            else{
                temp = temp->getLeft();//else go to left branch and continue recursion...
            }
        }
        else{
            if(temp->getRight() == NULL){
                temp->addRight(newNode);//if right of node is empty then insert node as right child
                break;
            }
            else{
                temp = temp->getRight();//else go to right branch and continue the recursion...
            }
        }
    }
    return;
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
    tree->insert(15);
    tree->insert(6);
    tree->insert(18);
    tree->insert(3);
    tree->insert(7);
    tree->insert(17);
    tree->insert(20);
    tree->insert(2);
    tree->insert(4);
    tree->insert(13);
    tree->insert(9);
    tree->printTree(IN_ORDER);   cout << endl;
    tree->printTree(PRE_ORDER);  cout << endl;
    tree->printTree(POST_ORDER); cout << endl;
    return 0;
}