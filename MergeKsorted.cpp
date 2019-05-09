#include "MergeKsorted.h"

MergeHeapNode::MergeHeapNode() {
  arr_index = 0;
  curr_index = 0;
}

MergeHeapNode::MergeHeapNode(int a_index, int c_index) {
  arr_index = a_index;
  curr_index = c_index;
}

MergeHeap::MergeHeap() {
  capacity = 10;
  size = 0;
  heap = (MergeHeapNode**)malloc(sizeof(MergeHeapNode)*capacity);
}

MergeHeap::MergeHeap(vector<vector<int>> *v) : MergeHeap() {
  sorted_arrays = v;
}

int MergeHeap::getLeft(int i) {
  int leftIndex = 2*i+1;
  return leftIndex > this->size-1 ? -1 : leftIndex;
}

int MergeHeap::getRight(int i) {
  int rightIndex = 2*i+2;
  return rightIndex > this->size-1 ? -1 : rightIndex;
}

int MergeHeap::getValueFromVector(int i,int j) {
  if(j >= (*sorted_arrays)[i].size()) {
    return INT16_MAX;
  }
  return (*sorted_arrays)[i][j];
}

int MergeHeap::getValueFromNode(MergeHeapNode* n) {
  return this->getValueFromVector(n->arr_index, n->curr_index);
}

int MergeHeap::getParent(int i) {
  if(i<=0 || i>this->size-1) {
    return -1;
  }
  return i/2;
}

int MergeHeap::resizeHeap() {
  MergeHeapNode** old_heap = this->heap;
  MergeHeapNode** new_heap = NULL;
  new_heap = (MergeHeapNode**)malloc(this->capacity*2*sizeof(MergeHeapNode));
  if(!new_heap) {
    cout << "Unable to allocate requested memory: " << this->capacity*2;
    return -1;
  }
  for(int i=0;i<this->capacity;i++) {
    new_heap[i] = old_heap[i];
  }
  free(old_heap);
  this->heap = new_heap;
  this->capacity = this->capacity*2;
  return 1;
}

void MergeHeap::insert(int arr_index, int curr_index) {
  int value = this->getValueFromVector(arr_index, curr_index);
  if(this->size+1 >= this->capacity) {
    int status = this->resizeHeap();
    if(status < 0) {
      cout << "Failed to insert into heap: " << value << endl;
      return;
    }
  }
  MergeHeapNode* newNode = new MergeHeapNode(arr_index, curr_index);
  this->heap[this->size++] = newNode;
  int currentIndex = this->size-1;
  int parentIndex = this->getParent(currentIndex);
  while(parentIndex >= 0) {
    int parent = this->getValueFromNode(this->heap[parentIndex]);
    if(value < parent) {
      //Swap current node and parent
      this->swap(parentIndex, currentIndex);
    }
    //Move up each index by one level
    currentIndex = parentIndex;
    parentIndex = this->getParent(parentIndex);
  }
}

void MergeHeap::swap(int i, int j) {
  MergeHeapNode* temp = this->heap[i];
  this->heap[i]  = this->heap[j];
  this->heap[j]  = temp;
}

int MergeHeap::getMin() {
  if(this->size > 0) {
    MergeHeapNode *n = this->heap[0];
    return getValueFromVector(n->arr_index, n->curr_index);
  }
  cout << "Heap is empty" << endl;
  return INT_MAX;
}

MergeKsorted::MergeKsorted() {
  arr = { { 2, 6, 12 }, 
          { 1, 9 }, 
          { 23, 34, 90, 2000 } 
        };
  h = new MergeHeap();
}

void MergeKsorted::merge() {

}

int main() {
  cout << "Hello world in MH\n";
  MergeKsorted *m = new MergeKsorted();
  m->merge();
  return 0;
}