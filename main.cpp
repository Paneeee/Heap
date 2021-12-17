#include <iostream>
#include "Heap.cpp"
#include "Heap.h"
using namespace std;

int main(){
    maxHeap <int> *test = new maxHeap<int>();
    int a[10]={52,35,67,27,93,13,92,23,54,28};
    for (int i=0; i<10; i++){
        test->insert(a[i]);
    }
    test->print();
    maxHeap<int>::buildAHeap(&a[0],10);
    for (int i=0; i<10; i++){
        cout<<a[i]<<" ";
    }
    delete test;
    return 0;
}