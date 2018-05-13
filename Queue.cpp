#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

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

Queue::Queue(int size){
    this->size  = size;
    this->front = -1;
    this->rear  = -1;
    this->arr   = (int*)malloc(size*sizeof(int));
}

Queue::~Queue(){
    free(arr);
}

int Queue::getSize(){
    return size;
}

bool Queue::isFull(){
    if(rear == size-1){
        cout << "Queue is Full" << endl;
        return true;
    }
    return false;
}

bool Queue::isEmpty(){
    if(front > rear || front == -1){
        cout << "Queue is Empty" << endl;
        return true;
    }
    return false;
}

void Queue::enQueue(int element){
    if(isFull())
        return;
    if(front == -1)
        front++;
    arr[++rear] = element;
}

int Queue::deQueue(){
    if(isEmpty()){
        return INT_MIN;
    }
    int element = arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return element;
    }
    front++;
    return element;
}

void Queue::printQueue(){
    for(int i=front;i<=rear;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    Queue *q = new Queue(3);
    q->enQueue(10);
    q->enQueue(20);
    q->enQueue(30);
    q->printQueue();
    cout << q->deQueue() << endl;
    q->printQueue();
    return 0;
}