class Queue{
    private:
        int *arr;
        int size;
        int front;
        int rear;
    public:
        Queue();
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        int getSize();
        void enQueue(int element);
        int  deQueue();
        void printQueue();
};
