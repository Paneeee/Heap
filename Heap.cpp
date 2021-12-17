#include "Heap.h"

//===============Node===============

//===============minHeap===============

//===============maxHeap===============
template<class T>
maxHeap<T>::maxHeap(){
    size=0;
    capacity=10;
    arr = new T [capacity];
}
template<class T>
maxHeap<T>::maxHeap(int capacity){
    size=0;
    this->capacity=capacity;
    arr = new T [capacity];
}

template<class T>
void maxHeap<T>::ensureCapacity(){
    capacity=capacity*3/2+1;
    T* newArr= new T[capacity];
    memmove(newArr,arr,capacity*sizeof(T));
    delete []arr;
    arr = newArr;
}
template<class T>
bool maxHeap<T>::insert(T value){
    if (size>=capacity)
        ensureCapacity();
    arr[size]=value;
    size++;
    reheapUp(size-1);
    return true;
}
template<class T>
T maxHeap<T>::delete1(int pos){
    if (pos<0 || pos>=size)
        return -1;
    T res=arr[0];
    arr[0]=arr[size-1];
    arr[size-1]=0;
    size--;
    reheapDown(0);
    return res;
    
}

//int search(T value);
template<class T>
void maxHeap<T>::reheapUp(int i){
    if (size<=1)
        return;
    if (i>0){
        int par=parent(i);
        if (arr[par]<arr[i]){
            swap(par,i);
            reheapUp(par);
        }
    }
}
template<class T>
void maxHeap<T>::reheapDown(int i){
    if (size<=1)
        return;
    int left=leftChild(i),right=rightChild(i);
    if (left<size){
        int large=0;
        if (right<size &&arr[right]>arr[i])
            large=right;
        else 
            large=left;
        if (arr[large]>arr[i])
        {
            swap(i,large);
            reheapDown(large);
        }
    }
}

template<class T>
int maxHeap<T>::leftChild(int i){
    return 2*i+1;
}
template<class T>
int maxHeap<T>::rightChild(int i){
    return 2*i+2;
}
template<class T>
int maxHeap<T>::parent(int i){
    return (i-1)/2;
}
template<class T>
void maxHeap<T>::swap(int i, int j){
    T temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
template<class T>
void maxHeap<T>::print(){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
maxHeap<T>::~maxHeap(){
    delete []arr;
    size=0;
    capacity=0;
}
template<class T>
void maxHeap<T>::buildAHeap(T *start, int size){
    for (int i=1;i<size;i++){
        bottomUp(start,size,i);
    }
}
template<class T>
void maxHeap<T>::bottomUp(T* start, int size, int i){
    if (size<=1)
        return;
    if (i>0){
        int par=(i-1)/2;
        if (start[par]<start[i]){
            T temp = start[par];
            start[par]=start[i];
            start[i]=temp;
            bottomUp(start,size,par);
        }
    }
}