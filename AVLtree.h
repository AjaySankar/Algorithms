#include "AVL_Node.h"
#include<queue>
#include<stack>
enum Traversal_Type{PRE_ORDER=1,IN_ORDER,POST_ORDER};
class AVL{
    public:
        AVL_Node* root;
    public:
        AVL();
        AVL(AVL_Node* );
        AVL_Node* insert(AVL_Node* node, int value);
        void printTree(Traversal_Type type);
        void Inorder(AVL_Node* root);
        AVL_Node* getRoot();
};
