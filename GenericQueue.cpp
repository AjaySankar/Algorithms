#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include "GenericQueue.h"
using namespace std;

template <class T>
Queue<T>::Queue(int size){
    this->size  = size;
    this->front = -1;
    this->rear  = -1;
    this->arr   = (T*)malloc(size*sizeof(T));
}

template <class T>
Queue<T>::~Queue(){
    free(arr);
}

template <class T>
int Queue<T>::getSize(){
    return size;
}

template <class T>
bool Queue<T>::isFull(){
    if(rear == size-1){
        cout << "Queue is Full" << endl;
        return true;
    }
    return false;
}

template <class T>
bool Queue<T>::isEmpty(){
    if(front > rear || front == -1){
        cout << "Queue is Empty" << endl;
        return true;
    }
    return false;
}

template <class T>
void Queue<T>::enQueue(T element){
    if(isFull())
        return;
    if(front == -1)
        front++;
    arr[++rear] = element;
}

template <class T>
T Queue<T>::deQueue(){
    if(isEmpty()){
        return INT_MIN;
    }
    T element = arr[front];
    if(front == rear){
        front = -1;
        rear = -1;
        return element;
    }
    front++;
    return element;
}

template <class T>
void Queue<T>::printQueue(){
    for(int i=front;i<=rear;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int tmain(){
    Queue<int> *q = new Queue<int>(3);
    q->enQueue(10);
    q->enQueue(20);
    q->enQueue(30);
    q->printQueue();
    cout << q->deQueue() << endl;
    q->printQueue();
    return 0;
}
