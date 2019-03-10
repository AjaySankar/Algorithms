#include<iostream>
#include<stdlib.h>
#include"stack.h"
#include<bits/stdc++.h>
using namespace std;

Stack::Stack(int size){
    this->size = size;
    this->top  = -1;
    this->arr  = (int*)malloc(size*sizeof(int));
}

Stack::~Stack(){
    free(arr);
}

int Stack::getSize(){
    return size;
}

bool Stack::isFull(){
    if(top == size-1){
        cout << "Stack Full" << endl;
        return true;
    }
    return false;
}

bool Stack::isEmpty(){
    if(top == -1){
        //cout << "Stack empty" << endl;
        return true;
    }
    return false;
}

void Stack::push(int element){
    if(!isFull())
        arr[++top] = element;
}

int Stack::pop(){
    if(!isEmpty())
        return arr[top--];
    return INT_MIN;
}

int Stack::getTop(){
    if(!isEmpty())
        return arr[top];
    return INT_MIN;
}

void Stack::printStack(){
    if(isEmpty())
        return;
    for(int i=top;i>=0;i--)
        cout << arr[i] << " ";
    cout << endl;
}

void Stack::insertAtBottom(int value) {
    if(this->isEmpty()) {
        this->push(value);
        return;
    }
    int data = this->pop();
    insertAtBottom(value);
    this->push(data);
}

void Stack::reverseStack() {
    //In place stack reversal
    if(this->isEmpty()) {
        return;
    }
    int data = this->pop();
    this->reverseStack();
    this->insertAtBottom(data);
}

int main(){
    Stack *s1 = new Stack(6);
    s1->push(10);
    s1->push(20);
    s1->push(30);
    s1->push(40);
    s1->push(50);
    s1->push(60);
    s1->printStack();
    /*cout << s1->pop() << endl;
    s1->printStack();
    s1->insertAtBottom(50);
    s1->printStack();*/
    s1->reverseStack();
    s1->printStack();
    return 0;
}