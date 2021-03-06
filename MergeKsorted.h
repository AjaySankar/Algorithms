#include<iostream>
#include<algorithm>
#include<climits>
#include <vector>
using namespace std;
//This is a min heap for now..

class MergeHeapNode {
  public:
    int arr_index;
    int curr_index;
  MergeHeapNode();
  MergeHeapNode(int arr_index, int curr_index);
  bool isInfiniteNode();
  void printNode();
};

class MergeHeap {
  public:
    MergeHeapNode** heap;
    int capacity;
    int size;
    vector<vector<int>> *sorted_arrays;
  public:
    MergeHeap();
    MergeHeap(vector<vector<int>> *v);
    int getLeft(int i);
    int getRight(int i);
    int getMin();
    int getValueFromVector(int i,int j);
    int getValueFromNode(MergeHeapNode* n);
    int getParent(int i);
    int resizeHeap();
    void insert(int arr_index, int curr_index);
    void swap(int i, int j);
    MergeHeapNode* extractMin();
    void percolateDown(int index);
    int getMin(int left, int right, int index);
    void printHeap();
};

class MergeKsorted {
  public:
    MergeHeap *h;
    vector<vector<int>> *arr;
  public:
    MergeKsorted(vector<vector<int>> *arr);
    void merge(vector<int> *arr);
    void printSortedArrays();
  private:
    void initHeap();
};