class Stack {
    private:
        int *arr;
        int size;
        int top;
    public:
        Stack();
        Stack(int n);
        ~Stack();
        int getSize();
        bool isFull();
        bool isEmpty();
        void push(int element);
        int pop();
        void printStack();
        int getTop();
        void insertAtBottom(int val);
        void reverseStack();
};