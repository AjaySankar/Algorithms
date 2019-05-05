#include "Heap.h"

Heap::Heap() {
  capacity = 10;
  size = 0;
  heap = (int*)malloc(sizeof(int)*capacity);
}

int Heap::getLeft(int i) {
  int leftIndex = 2*i+1;
  return leftIndex > this->size-1 ? -1 : leftIndex;
}

int Heap::getRight(int i) {
  int rightIndex = 2*i+2;
  return rightIndex > this->size-1 ? -1 : rightIndex;
}

int Heap::getMin() {
  if(this->size > 0) {
    return this->heap[0];
  }
  cout << "Heap is empty" << endl;
  return INT_MAX;
}

int Heap::getParent(int i) {
  if(i<=0 || i>this->size-1) {
    return -1;
  }
  return i/2;
}

int Heap::resizeHeap() {
  int* old_heap = this->heap;
  int* new_heap = NULL;
  new_heap = (int*)malloc(this->capacity*2*sizeof(int));
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

void Heap::insert(int value) {
  if(this->size+1 >= this->capacity) {
    int status = this->resizeHeap();
    if(status < 0) {
      cout << "Failed to insert into heap: " << value << endl;
      return;
    }
  }
  this->heap[this->size++] = value;
  int currentIndex = this->size-1;
  int parentIndex = this->getParent(currentIndex);
  while(parentIndex >= 0) {
    int parent = this->heap[parentIndex];
    if(value < parent) {
      //Swap current node and parent
      this->heap[parentIndex] = value;
      this->heap[currentIndex]  = parent;
    }
    //Move up each index by one level
    currentIndex = parentIndex;
    parentIndex = this->getParent(parentIndex);
  }
}

void Heap::swap(int i, int j) {
  int temp = this->heap[i];
  this->heap[i]  = this->heap[j];
  this->heap[j]  = temp;
}

int Heap::getMin(int left, int right, int index) {
  int leftChild = left > 0 ? this->heap[left] : INT_MAX;
  int rightChild = left > 0 ?  this->heap[right] : INT_MAX;
  int minIndex = leftChild < rightChild ? left : right;
  minIndex = this->heap[minIndex] < this->heap[index] ? minIndex : index;
  return minIndex;
}

int Heap::extractMin() {
  if(this->size == 0) {
    cout << "Heap is empty" << endl;
    return INT_MAX;
  }
  swap(0, this->size-1);
  int min = this->heap[this->size-1];
  this->size--;
  percolateDown(0);
  return min;
}

void Heap::percolateDown(int index) {
  while(1) {
    int leftIndex = this->getLeft(index);
    int rightIndex = this->getRight(index);
    int minIndex = getMin(leftIndex, rightIndex, index);
    if(minIndex == index) {
      break;
    }
    swap(index, minIndex);
    index = minIndex;
    leftIndex = this->getLeft(index);
    rightIndex = this->getRight(index);
  }
}

void Heap::buildHeap(int arr[], int n) {
  if(n <= 0) {
    cout << "Cannot build heap with an empty array" << endl;
    return;
  }

  while(this->capacity >= n) {
    //Expand heap size as per requirement
    int status = resizeHeap();
    if(status == -1) {
      cout << "Failed to build heap" << endl;
      return;
    }
  }

  for(int i=0;i<n;i++) {
    this->heap[i] = arr[i];
  }
  this->size = n;
  for(int i=n/2;i>=0;i--) {
    percolateDown(i);
  }
}

void Heap::heapSort(int arr[], int n) {
  buildHeap(arr,n);
  while(this->size > 0) {
    int min = extractMin();
    cout << min << " ";
  }
  cout << endl;
}

void Heap::printHeap() {
  for(int i=0;i<this->size;i++) {
    cout << this->heap[i] << " ";
  }
  cout << endl;
}

int main() {
  Heap *h = new Heap();
  int arr[11] = {31,10,21,5,8,12,18,3,2,1,7};
  h->heapSort(arr,11);
  return 0;
}