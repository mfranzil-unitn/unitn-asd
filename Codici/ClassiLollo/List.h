#ifndef _LIST_H
#define _LIST_H
#include <iostream>
using namespace std;

template<class Item>
class List{
    protected:
        List* pred;
        List* succ;
        Item value;
    public:
        List(){
            this->pred = this;
            this->succ = this;
            //this->value = 
        }
        ~List(){
            //cout << "Oggetto List [" << this->value << "] distrutto" << endl;
        }
        bool empty(){
            return (this->pred == this->succ && this->succ == this);
        }
        List* head(){
            return this->succ;
        }
        List* tail(){
            return this->pred;
        }
        static void deleteAllList(List* p){
            while(!p->empty()){
                p = remove(p);
            }
            delete p;
        }
        static List* next(List* p){
            return p->succ;
        }
        static List* prev(List* p){
            return p->pred;
        }
        //bool finished(List*);  //??
        static Item read(List* p){
            return p->value;
        }
        static void write(List* p, Item v){
            p->value = v;
        }
        static List* insert(List* p, Item v){
            List* t = new List();
            t->value = v;
            t->pred = p->pred;
            p->pred->succ = t;
            t->succ = p;
            p->pred = t;
            return t;
        }
        static List* remove(List* p){
            List* t = p->succ;
            p->pred->succ = p->succ;
            p->succ->pred = p->pred;
            delete p;
            return t;
        }
        static List* print(List* p){
            List* t = p->head();
            while(t != p){
                cout << "[" << t->value << "]->";
                t = List::next(t);
            }
        }
        int size(){
            List* t = this->head();
            int s = 0;
            while(t != this){
                s++;
                t = List::next(t);
            }
            return s;
        }
        Item readAt(int index){
            Item v;
            List* t = this->head();
            for(int i = 0; t != this && i < index+1; i++){
                if(i == index)
                    v = t->value;
                t = List::next(t);        
            }
            return v;
        }
        List* at(int index){
            List* v;
            List* t = this->head();
            for(int i = 0; t != this && i < index+1; i++){
                if(i == index)
                    v = t;
                t = List::next(t);        
            }
            return v;
        }
        List* clone(){
            List* n = new List();
            List* t = this->head();
            for(int i = 0; t != this; i++){
                insert(n, read(t));
                t = List::next(t);
            }
            return n;
        }
        List* found(Item v){
            List* t = this->head();
            List* r = NULL;
             for(int i = 0; t != this; i++){
                if(t->readAt(i) == v)
                    r = t;
                t = List::next(t);        
            }
            return r;
        }
};
#endif