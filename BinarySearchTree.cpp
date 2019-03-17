#include<iostream>
#include<algorithm>
using namespace std;
#include "BST.h"
#include "stdio.h"

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
    //Need to set proper parent pointers of all the nodes modifies in all the below cases
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
                    //We need a node(successor) with value greater than passed value and once finding
                    //such node(temp), then go to its left beacuse the left subtree may contain a value
                    //that is > than passed value and < than temp which will be a closer inorder successor
                    //than temp.
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

int BST::getDepth(BST_Node* node){
    //This method return the level of the node from root where root is at level 1
    int level = 0;
    BST_Node* temp = root;
    while(temp){
        level++;
        if(temp->getValue() < node->getValue()){
            temp = temp->getRight();
        }
        else if (temp->getValue() > node->getValue())
        {   
            temp = temp->getLeft();
        }
        else{
            break;
        }
    }
    return level;
}

BST_Node* BST::getLCA(BST_Node* node1,BST_Node* node2){
    int level1 = getDepth(node1);
    int level2 = getDepth(node2);
    if(node1 == node2)
        return node1;
    if(node1->getParent() == node2->getParent())
        return node1->getParent();
    if(level1 > level2)
        return getLCA(node1->getParent(),node2);
    else
        return getLCA(node1,node2->getParent());
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

int BST::getHeight(BST_Node* root) {
    if(!root)
        return 0;
    int leftHeight = getHeight(root->getLeft());
    int rightHeight = getHeight(root->getRight());
    return std::max(leftHeight,rightHeight)+1;
}

void BST::levelOrderTraversal() {
    queue <BST_Node*> q;
    q.push(root);
    while(!q.empty()){
      BST_Node* node = q.front();
      q.pop();
      cout << node->getValue() << " ";
      if(node->getLeft())
        q.push(node->getLeft());
      if(node->getRight())
        q.push(node->getRight());
    }
    cout << endl;
}

int BST::getLevelCount() {
   int levels = 0;
    queue <BST_Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
      BST_Node* node = q.front();
      q.pop();
      if(!node) {
        if(!q.empty()) {
          q.push(NULL);
        }
        levels++;
      }
      else {
        if(node->getLeft())
          q.push(node->getLeft());
        if(node->getRight())
          q.push(node->getRight());
      }
    }
    return levels;
}

void BST::PrintPaths(BST_Node* root,int path[], int pathLen){
  if(root == NULL)
    return;
  path[pathLen] = root->getValue();
  pathLen++;
  if(root->getLeft() == NULL && root->getRight() == NULL){
    for(int i=0;i<pathLen;i++)
      printf("%d ",path[i]);
    printf("\n");
  }
  else {
    PrintPaths(root->getLeft(), path, pathLen);
    PrintPaths(root->getRight(), path, pathLen);
  }
}

bool BST::printAncestor(BST_Node* root, BST_Node* node) {
    //Base case 1
    if(root == NULL)
        return false;
    //Check if root is an immediate ancestor(parent) of the node and return true i,e find the node and it parent in the tree
    if(root->getLeft() == node || root->getRight() == node) {
        cout << "Parent " << root->getValue() << endl;
        return true;
    }
    //If not an immediate ancestor then check in LST to find for such ancestor
    bool foundInLST = printAncestor(root->getLeft(), node);
    if(foundInLST) {
        cout << "Ancestor: " << root->getValue() << endl;
    }
    //If not an immediate ancestor then check in RST to find for such ancestor
    bool foundInRST = printAncestor(root->getRight(), node);
    if(foundInRST) {
        cout << "Ancestor: " << root->getValue() << endl;
    }
    //Return if found in either LST or RST of the root so that root can be printed as one of the ancestors
    return foundInLST || foundInRST;
}

void BST::printInorderIterative(BST_Node* root) {
    stack <BST_Node*> s;
    while(1){
        //Add all left nodes by going deeply in left nodes
        while(root) {
            s.push(root);
            root = root->getLeft();
        }
        if(s.empty()) 
            break;
        root = s.top(); s.pop();
        //Print after popping out (visting node second time) which is the principle of inorder
        cout << root->getValue() << " ";
        //Explored left sub tree and root and no go on with exploring right sub tree
        root = root->getRight();
    }
    
}

void BST::printPreorderIterative(BST_Node* root) {
    stack <BST_Node*> s;
    while(1){
        //Add all left nodes by going deeply in left nodes
        while(root) {
            s.push(root);
            //Print when the node is pushed (visited first time) which is the principle of preorder
            cout << root->getValue() << " ";
            root = root->getLeft();
        }
        if(s.empty()) 
            break;
        root = s.top(); s.pop();
        //Explored left sub tree and root and no go on with exploring right sub tree
        root = root->getRight();
    }
    
}

void BST::fillStack(BST_Node* node, stack<BST_Node*>* s) {
    BST_Node* temp = root;
    while(1){
        s->push(temp);
        if(temp->getValue() == node->getValue())
            break;
        if(temp->getValue() < node->getValue())
            temp = temp->getRight();
        else 
            temp = temp->getLeft();
    }
    //this->printStack(s);
}

void BST::printStack(stack<BST_Node*>* s) {
    while(!s->empty()){
        BST_Node* top = s->top();
        s->pop();
        cout << top->getValue() << " ";      
    }
    cout << endl;
}

void BST::iterativeFindLCA(BST_Node* alpha, BST_Node* beta) {
    stack <BST_Node*> alphaStack,betaStack;
    this->fillStack(alpha, &alphaStack);
    this->fillStack(beta, &betaStack);
    int alphaLength = alphaStack.size();
    int betaLength = betaStack.size();
    int lenDiff =  alphaLength > betaLength ? alphaLength - betaLength : betaLength - alphaLength;
    if(lenDiff) {
        stack <BST_Node*>* longerStack = alphaLength > betaLength ? &alphaStack : &betaStack;
        while(lenDiff) {
            longerStack->pop();
            lenDiff--;
        }
    }
    while(!alphaStack.empty() && !betaStack.empty()) {
        BST_Node* alphaTop = alphaStack.top(); BST_Node* betaTop = betaStack.top();
        if(alphaTop->getValue() == betaTop->getValue()) {
            cout << "LCA of " << alpha->getValue() << " " << beta->getValue() << " is: " << alphaTop->getValue() << endl;
            break;
        }
        alphaStack.pop();
        betaStack.pop();
    }
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
    //tree->printTree(PRE_ORDER);   cout << endl;
    //tree->printPreorderIterative(tree->getRoot()); cout << endl;
    //tree->levelOrderTraversal();
    //cout << "Number of levels in the tree: " << tree->getLevelCount() << endl;
    //int path[100];
    //tree->PrintPaths(tree->getRoot(), path, 0);
    /*cout << "The level of the node is " << tree->getDepth(tree->Search(15));
    cout << "The LCA is " << tree->getLCA(tree->Search(2),tree->Search(18))->getValue();
    tree->deleteNode(15);
    tree->printTree(IN_ORDER);   cout << endl;
    cout << tree->getHeight(tree->getRoot());*/
    //tree->printAncestor(tree->getRoot(), tree->Search(9));
    tree->iterativeFindLCA(tree->Search(20),tree->Search(7));
    return 0;
}
