#include<iostream>
#include<bits/stdc++.h>
#include"stack.h"
using namespace std;

class SQueue{
    private:
        Stack *primary;
        Stack *secondary;
        int length;
    public:
        SQueue();
        SQueue(int size);
        ~SQueue();
        bool isFull();
        bool isEmpty();
        int getSize();
        void enQueue(int element);
        int  deQueue();
        void printQueue();
};

SQueue::SQueue(int size){
    length    = size;
    primary   = new Stack(size);
    secondary = new Stack(size);
}

SQueue::~SQueue(){
    primary->~Stack();
    secondary->~Stack();
}

bool SQueue::isFull(){
    return primary->isFull();
}

bool SQueue::isEmpty(){
    return primary->isEmpty();
}

int SQueue::getSize(){
    return length;
}

void SQueue::enQueue(int element){
    if(isFull()){
        cout << "Queue is full" << endl;
        return;
    }
    primary->push(element);
}

int SQueue::deQueue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return INT_MIN;
    }
    while(!primary->isEmpty()){
        secondary->push(primary->pop());
    }
    int element = secondary->pop();
    while(!secondary->isEmpty()){
        primary->push(secondary->pop());
    }
    return element;
}

void SQueue::printQueue(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return;
    }
    while(!primary->isEmpty()){
        secondary->push(primary->pop());
    }
    while(!secondary->isEmpty()){
        int element = secondary->pop();
        cout << element << " ";
        primary->push(element);
    }
    cout << endl;
}

int main(){
    SQueue* sq = new SQueue(5);
    cout << sq->getSize() << endl;
    sq->enQueue(10);
    sq->enQueue(20);
    sq->enQueue(30);
    sq->enQueue(40);
    sq->enQueue(50);
    sq->printQueue();
    cout << sq->deQueue() << endl;
    sq->printQueue();
    return 0;
}