template <class T>
class Queue{
    private:
        T *arr;
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
        void enQueue(T element);
        T  deQueue();
        void printQueue();
};