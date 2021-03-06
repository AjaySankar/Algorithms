#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int value;
        Node* next;
    public:
        Node();
        Node* getNode(int element);
        int getValue();
        Node* getNext();
        void addNext(Node* newNode);
};

Node::Node(){
    value = INT_MIN;
    next = NULL;
}

Node* Node::getNode(int element){
    Node *temp = new Node();
    temp -> value = element;
    return temp;
}

int Node::getValue(){
    return value;
}

Node* Node::getNext(){
    return next;
}

void Node::addNext(Node *node){
    this->next = node;
}

class LinkedList{
    private:
        int length;
        Node *head;
    public:
        LinkedList();
        int getLength();
        bool isEmpty();
        void printList();
        void insert(int element);
        void remove(int element);
        int getNthNodeFromEnd(int n);
        void reverseList();
        void swapNodes();
};

LinkedList::LinkedList(){
    length = 0;
    head   = new Node();
}

int LinkedList::getLength(){
    return length;
}

bool LinkedList::isEmpty(){
    return length==0;
}

void LinkedList::printList(){
    Node* temp = head;
    while(temp !=NULL){
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int LinkedList::getNthNodeFromEnd(int n) {
    if(n < 0 || n > length) {
        return INT16_MIN;
    }
    Node* temp = head;
    Node* nthNode = head;
    int count = 0;
    while(temp != NULL) {
        temp = temp->getNext();
        count++;
        if(count > n)
            nthNode = nthNode->getNext();
    }
    return nthNode->getValue();
}

void LinkedList::insert(int element){
    Node* newNode = head->getNode(element);
    if(length == 0){
        head = newNode;
        length++;
        return;
    }
    Node* temp = head;
    while(temp -> getNext() !=NULL)
        temp = temp->getNext();
    temp->addNext(newNode);
    length++;
}

void LinkedList::remove(int element){
    if(isEmpty()){
        cout << "List is empty" << endl;
        return;
    }
    if(head->getValue() == element){
        Node* temp = head;
        head = head->getNext();
        length--;
        delete temp;
        return;
    }
    Node *prev = NULL;
    Node *current = head;
    while(current!=NULL && current->getValue()!=element){
        prev = current;
        current = current->getNext();
    }
    if(!current){
        cout << "Element is not found" << endl;
        return;
    }
    prev->addNext(current->getNext());
    length--;
    delete current;
}

void LinkedList::reverseList() {
    Node* temp = NULL; Node* nextNode = NULL;
    while(head) {
        nextNode = head->getNext();
        head->addNext(temp);
        temp = head;
        head = nextNode;
    }
    head = temp;
    this->printList();
}

void LinkedList::swapNodes() {
    if(!head) {
        cout << "List is empty" << endl;
        return;
    }
    Node* a = NULL;
    Node* b = head;
    if(!b->getNext()) {
        cout << "Length of the list is too short" << endl;
        return;
    }
    Node* c = b->getNext();
    while(b && c) {
        if(!a) {
            head = c;
        }
        else 
            a->addNext(c);
        b->addNext(c->getNext());
        c->addNext(b);
        a = b;
        b = b->getNext();
        c = b->getNext();
    }
    printList();
}

int main(){
    LinkedList *list = new LinkedList();
    list->insert(10);
    list->insert(20);
    list->insert(30);
    list->insert(40);
    list->insert(50);
    list->insert(60);
    list->insert(70);
    list->insert(80);
    list->insert(90);
    cout << list->getLength() << endl;
    list->printList();
    list->swapNodes();
    //list->printList();
    //list->reverseList();
    //cout << list->getNthNodeFromEnd(9) << endl;
    //list->remove(30);
    //list->printList();
    //cout << list->getLength() << endl;
    return 0;
}