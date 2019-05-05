#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
//This is a min heap for now..
class Heap {
  public:
    int* heap;
    int capacity;
    int size;
  public:
    Heap();
    void insert(int value);
    int getParent(int i);
    void printHeap();
    int getLeft(int i);
    int getRight(int i);
    void percolateDown(int i);
    void swap(int i, int j);
    int getMin(int l, int r, int i);
    int resizeHeap();
    int getMin();
    int extractMin();
    void buildHeap(int arr[], int n);
    void heapSort(int arr[], int n);
};