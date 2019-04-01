#include<iostream>
#include<algorithm>
using namespace std;

class AVL_Node{
    public:
        int value;
        AVL_Node* left;
        AVL_Node* right;
        AVL_Node* parent;
        int height;
    public:
        AVL_Node();
        explicit AVL_Node(int element);
        int getValue();
        void setValue(int element);
        AVL_Node* getLeft();
        AVL_Node* getRight();
        AVL_Node* getParent();
        void setParent(AVL_Node* node);
        void addLeft(AVL_Node* node);
        void addRight(AVL_Node* node);
        int getHeight();
};
