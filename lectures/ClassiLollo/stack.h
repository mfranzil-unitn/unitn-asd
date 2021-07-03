#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "list.h"
using namespace std;

template <class Item>
class Stack {
   protected:
    List<Item>* s;

   public:
    Stack() {
        s = new List<Item>();
    }
    ~Stack() {
        List<Item>::deleteAllList(s);
        cout << "Oggetto Stack distrutto" << endl;
    }
    bool isEmpty() {
        return s->empty();
    }
    void push(Item v) {
        List<Item>::insert(s->head(), v);
    }
    Item pop() {
        List<Item>* h = s->head();
        Item v = List<Item>::read(h);
        s->remove(h);
        return v;
    }
    Item top() {
        return List<Item>::read(s->head());
    }
    void print() {
        List<Item>::print(s);
    }
};
#endif