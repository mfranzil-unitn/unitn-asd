#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <iostream>
#include "Queue.h"
using namespace std;

template<class Item>
class BinaryTree{
    protected:
        BinaryTree* parent;
        BinaryTree* right;
        BinaryTree* left;
        Item value;
    public:
        BinaryTree(Item v){
            this->parent = NULL;
            this->right = NULL;
            this-> left = NULL;
            this->value = v;
        }
        ~BinaryTree(){
            this->deleteLeft();
            this->deleteRight();
            //cout << "Oggetto albero [" << this->value << "] binario distrutto!" << endl;
        }
        BinaryTree* getParent(){
            return this->parent;
        }
        BinaryTree* getRight(){
            return this->right;
        }
        BinaryTree* getLeft(){
            return this->left;
        }
        Item getValue(){
            return this->value;
        }
        void insertLeft(Item v){
            BinaryTree* T = new BinaryTree(v);
            T->parent = this;
            this->left = T;
        }
        void insertRight(Item v){
            BinaryTree* T = new BinaryTree(v);
            T->parent = this;
            this->right = T;
        }
        void deleteRight(){
            if(this->right != NULL){
                this->right->deleteLeft();
                this->right->deleteRight();
                if(this->right != NULL)
                    delete this->left;
                this->right = NULL;
            }
        }
        void deleteLeft(){
            if(this->left != NULL){
                this->left->deleteLeft();
                this->left->deleteRight();
                if(this->left != NULL)
                    delete this->left;
                this->left = NULL;
            }
        }
        static void printPreVisit(BinaryTree* T){
            if(T != NULL){
                cout << T->value << endl;
                printPreVisit(T->left);
                printPreVisit(T->right);
            }
        }
        static void printBFS(BinaryTree* T){
            if(T != NULL){
                Queue<BinaryTree*>* Q = new Queue<BinaryTree*>();
                Q->enqueue(T);
                while(!Q->isEmpty()){
                    BinaryTree* u = Q->dequeue();
                    cout << "[" << u->value << "]" << endl;
                    if(u->left != NULL)
                        Q->enqueue(u->left);
                    if(u->right != NULL)
                        Q->enqueue(u->right);
                }
            }
        }
};
#endif