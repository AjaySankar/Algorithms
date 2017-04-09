#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MaxHeap{
    public:
            int *harr;
            int capacity;
            int heap_size;
            MaxHeap(int capacity);
            int parent(int i) { return (i-1)/2; }
            int left(int i) { return (2*i + 1); }
            int right(int i) { return (2*i + 2); }
            void insertKey(int k);
            void displayHeap();
            void removeRoot();
            void MaxHeapify(int index);
            void HeapSort();
};
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}
void MaxHeap::displayHeap(){
    for(int i=0;i<heap_size;i++)
        cout << harr[i] << " ";
    cout << endl;
}
void MaxHeap::MaxHeapify(int index){
    int largest=index;
    int index_left=left(index);
    int index_right=right(index);
    if(index_left<heap_size&&harr[index_left]>harr[largest])
        largest=index_left;
    if(index_right<heap_size&&harr[index_right]>harr[largest])
        largest=index_right;
    if(largest!=index){
        swap(&harr[index],&harr[largest]);
        MaxHeapify(largest);
    }
}
void MaxHeap::removeRoot(){
    cout << harr[0] << " ";
    harr[0]=harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);
}
void MaxHeap::insertKey(int k){
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;
    while(i>=0&&harr[i]>harr[parent(i)]){
        swap(&harr[i], &harr[parent(i)]);
        i=parent(i);
    }
}
void MaxHeap::HeapSort(){
    for(int i=heap_size-1;i>=0;i--){
        removeRoot();
    }
}
int main() {
	MaxHeap h(7);
	h.insertKey(1);
	h.insertKey(2);
	h.insertKey(3);
	h.insertKey(4);
	h.insertKey(5);
	h.insertKey(6);
	h.insertKey(7);
	h.HeapSort();
	return 0;
}
