#include "MergeKsorted.h"

MergeHeapNode::MergeHeapNode() {
  arr_index = -1;
  curr_index = -1;
}

MergeHeapNode::MergeHeapNode(int a_index, int c_index) {
  arr_index = a_index;
  curr_index = c_index;
}

bool MergeHeapNode::isInfiniteNode() {
  if(this->arr_index < 0 || this->curr_index < 0) {
    return true;
  }
  return false;
}

void MergeHeapNode::printNode() {
  cout << arr_index << " " << curr_index << endl;
}

MergeHeap::MergeHeap() {
  capacity = 50;
  size = 0;
  heap = (MergeHeapNode**)malloc(sizeof(MergeHeapNode*)*capacity);
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
  if(i < 0 || j < 0 || j >= (*sorted_arrays)[i].size()) {
    return INT_MAX;
  }
  return (*sorted_arrays)[i][j];
}

int MergeHeap::getValueFromNode(MergeHeapNode* n) {
  if(n->arr_index < 0 || n->curr_index < 0) {
    return INT_MAX;
  }
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
  new_heap = (MergeHeapNode**)malloc(this->capacity*2*sizeof(MergeHeapNode*));
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
  if(this->size+1 >= this->capacity) {
    int status = this->resizeHeap();
    if(status < 0) {
      cout << "Failed to insert into heap at : " << arr_index << " " << curr_index << endl;
      return;
    }
  }
  int value = this->getValueFromVector(arr_index, curr_index);
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

MergeHeapNode* MergeHeap::extractMin() {
  if(this->size == 0) {
    cout << "Heap is empty" << endl;
    MergeHeapNode* infNode = new MergeHeapNode(-1,-1);
    return infNode;
  }
  swap(0, this->size-1);
  MergeHeapNode* min = this->heap[this->size-1];
  this->size--;
  percolateDown(0);
  return min;
}

int MergeHeap::getMin(int left, int right, int index) {
  int leftChild = left > 0 ? getValueFromNode(this->heap[left]) : INT_MAX;
  int rightChild = right > 0 ?  getValueFromNode(this->heap[right]) : INT_MAX;
  int minIndex = leftChild < rightChild ? left : right;
  if(minIndex < 0)  //When both left and right child are empty then current node will be the minimum
    return index;
  minIndex = getValueFromNode(this->heap[minIndex]) < getValueFromNode(this->heap[index]) ? minIndex : index;
  return minIndex;
}

void MergeHeap::percolateDown(int index) {
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

void MergeHeap::printHeap() {
  for(int i=0;i<this->size;i++) {
    int value = this->getValueFromNode(this->heap[i]);
    cout << value << " ";
  }
  cout << endl;
}

MergeKsorted::MergeKsorted(vector<vector<int>> *arr) {
  this->arr = arr;
  h = new MergeHeap(arr);
}

void MergeKsorted::initHeap() {
  for(unsigned int i=0;i<arr->size();i++) {
    this->h->insert(i,0);
  }
}

void MergeKsorted::printSortedArrays() {
  vector<int>::iterator col;
  vector< vector<int> >::iterator row;
  for (row = arr->begin(); row != arr->end(); row++) {
    for (col = row->begin(); col != row->end(); col++) {
        cout << *col << " ";
    }
    cout << endl;
  }

  vector<int> *temp = &(arr[0][2]);
  for (col = temp->begin(); col != temp->end(); col++) {
    cout << *col << " ";
  }
}

void MergeKsorted::merge(vector<int> *sortedList) {
  this->initHeap();
  while(this->h->size) {
    MergeHeapNode *min = this->h->extractMin();
    if(min->isInfiniteNode()) {
      //After extractng minimum node from current heap, if it is an infinite node, it means that
      //no elements are available in other lists
      break;
    }
    sortedList->push_back(h->getValueFromNode(min));
    MergeHeapNode *newNode;
    vector<int> *currArray = &(arr[0][min->arr_index]);
    if(min->curr_index < currArray->size()-1) {
      this->h->insert(min->arr_index, min->curr_index+1);
    }
    else {
      this->h->insert(-1,-1);
    }
    free(min);
  }
}

int main() {
  vector<vector<int>> arr = { { 2, 6, 12 }, 
          { 1, 9 }, 
          { 23, 34, 90, 2000 } 
        };
  vector<int> finalSortedList;
  MergeKsorted *m = new MergeKsorted(&arr);
  m->merge(&finalSortedList);
  for (auto i = finalSortedList.begin(); i != finalSortedList.end(); ++i) {
    cout << *i << ' ';
  }
  return 0;
}