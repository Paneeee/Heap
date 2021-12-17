#include <iostream>
#include <string.h>
#pragma once
using namespace std;

/*
template <class T>
class minHeap{
    public:
    T *arr;
    int numOfNodes;

    minHeap();

};
*/
template <class T>
class maxHeap{
    public:
    T *arr;
    int size;
    int capacity;

    maxHeap();
    maxHeap(int capacity);

    void ensureCapacity();
    bool insert(T value);
    T delete1(int pos);       //delete root only
    //int search(T value);
    void reheapUp(int i);
    void reheapDown(int i);


    int leftChild(int i);
    int rightChild(int i);
    int parent(int i);
    void swap(int i, int j);
    void print();

    static void buildAHeap(T *start, int size);
    static void bottomUp(T* start, int size, int i);
    ~maxHeap();
};