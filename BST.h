#include "BST_Node.h"
#include<queue>
#include<stack>
enum Traversal_Type{PRE_ORDER=1,IN_ORDER,POST_ORDER};
class BST{
    protected:
        BST_Node* root;
    public:
        BST();
        BST(BST_Node* );
        void insert(BST_Node* node);
        void insertValue(int element);
        void printTree(Traversal_Type type);
        void Inorder(BST_Node* root);
        void Preorder(BST_Node* root);
        void Postorder(BST_Node* root);
        bool isLeaf(BST_Node* node);
        bool hasLeftChild(BST_Node* node);
        bool hasRightChild(BST_Node* node);
        bool isLeftChild(BST_Node* parent,BST_Node* child);
        bool isRightChild(BST_Node* parent,BST_Node* child);
        BST_Node* getMinimum();
        BST_Node* getMaximum();
        BST_Node* getRoot();
        BST_Node* Search(int value);
        BST_Node* SearchForParent(int value);
        BST_Node* getInorderSuccessor(int value);
        int getDepth(BST_Node* node);
        BST_Node* getLCA(BST_Node* node1,BST_Node* node2);
        void deleteNode(int element);
        int getHeight(BST_Node* root);
        void levelOrderTraversal();
        int getLevelCount();
        void PrintPaths(BST_Node* root,int path[], int pathLen);
        bool printAncestor(BST_Node* root, BST_Node* node);
        void printInorderIterative(BST_Node* root);
        void printPreorderIterative(BST_Node* root);
        void iterativeFindLCA(BST_Node* alpha, BST_Node* beta);
        void fillStack(BST_Node* node, stack<BST_Node*>* s);
        void printStack(stack<BST_Node*>* s);
        void pushPathToStack(BST_Node* root,BST_Node* path[], int pathLen, int data, stack<BST_Node*>* s);
};
