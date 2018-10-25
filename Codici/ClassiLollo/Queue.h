#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "list.h"
using namespace std;

template <class Item>
class Queue {
   protected:
    List<Item>* q;

   public:
    Queue() {
        q = new List<Item>();
    }
    ~Queue() {
        List<Item>::deleteAllList(q);
        cout << "Oggetto Queue distrutto" << endl;
    }
    bool isEmpty() {
        return q->empty();
    }
    void enqueue(Item v) {
        List<Item>::insert(q->head(), v);
    }
    Item dequeue() {
        List<Item>* t = q->tail();
        Item v = List<Item>::read(t);
        List<Item>::remove(t);
        return v;
    }
    Item top() {
        return List<Item>::read(q->tail());
    }
    void print() {
        List<Item>::print(q);
    }
};
#endif