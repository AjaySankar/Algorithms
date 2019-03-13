#define INT16_MIN -32768

class BST_Node{
    private:
        int value;
        BST_Node* left;
        BST_Node* right;
        BST_Node* parent;
    public:
        BST_Node();
        explicit BST_Node(int element);
        int getValue();
        void setValue(int element);
        BST_Node* getLeft();
        BST_Node* getRight();
        BST_Node* getParent();
        void setParent(BST_Node* node);
        void addLeft(BST_Node* node);
        void addRight(BST_Node* node);
};
