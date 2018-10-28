#ifndef ABR_H
#define ABR_H
#include <iostream>
#include "BinaryTree.h"
using namespace std;

enum Color { BLACK,
             RED };

template <class Item>
class ABR : public BinaryTree<Item> {
   protected:
    ABR* parent;
    ABR* right;
    ABR* left;
    Item key;
    Color color;

   public:
    ABR(Item x, Item v) : BinaryTree<Item>(v) {
        this->key = x;
    }
    ~ABR() {
        cout << "Oggetto ABR distrutto!" << endl;
    }
    static ABR* lookupNode(ABR* T, Item x) {  //Statico?
        if (T != NULL && T->key != x)
            return (x < T->key) ? lookupNode(T->left, x) : lookupNode(T->right, x);
        else
            return T;
    }
    static void link(ABR* p, ABR* u, Item x) {
        if (u != NULL)
            u->parent = p;
        if (p != NULL)
            if (x < p->key)
                p->left = u;
            else
                p->right = u;
    }
    static ABR* insertNode(ABR* T, Item x, Item v, bool mode) {  //Statico?
        ABR* p = NULL;
        ABR* u = T;
        ABR* n;
        while (u != NULL && u->key != x) {
            p = u;
            u = (x < u->key) ? u->left : u->right;
        }
        if (u != NULL && u->key == x)
            u->value = v;
        else {
            ABR* n = new ABR(x, v);
            link(p, n, x);
            if (mode) balanceInsert(n);
            while (n->parent != NULL)
                n = n->parent;
            return n;
        }
        return T;
    }
    static void balanceInsert(ABR* t) {
        t->color = RED;
        while (t != NULL) {
            ABR* p = (t->parent != NULL) ? t->parent : t;
            ABR* n = (p->parent != NULL) ? p->parent : t;
            ABR* z = (n == t) ? NULL : ((n->left == p) ? n->right : n->left);

            if (p == t) {
                t->color = BLACK;
                t = NULL;
            } else if (p->color == BLACK)
                t = NULL;
            else if (z != NULL && z->color == RED) {
                p->color = BLACK;
                z->color = BLACK;
                n->color = RED;
                t = n;
            } else {
                if (t == p->right && p == n->left) {
                    rotateLeft(p);
                    t = p;
                } else if (t == p->left && p == n->right) {
                    rotateRight(p);
                    t = p;
                } else {
                    if (t == p->left && p == n->left)
                        rotateRight(n);
                    else if (t == p->right && p == n->right)
                        rotateLeft(n);
                    p->color = BLACK;
                    n->color = RED;
                    t = NULL;
                }
            }
        }
    }
    static ABR* removeNode(ABR* T, Item x) {  //Statico?
        ABR* t = NULL;
        ABR* u = lookupNode(T, x);
        if (u != NULL) {
            if (u->left != NULL && u->right != NULL) {
                ABR* s = u->right;
                while (s->left != NULL)
                    s = s->left;
                u->key = s->key;
                u->value = s->value;
                u = s;
                x = s->key;
            }
            if (u->left != NULL && u->right == NULL)
                t = u->left;
            else
                t = u->right;
            link(u->parent, t, x);
            if (u->color == BLACK) {
                balanceDelete(T, t);
            }
            if (u->parent == NULL)
                T = t;
            delete u;
        }
        return T;
    }

    static void balanceDelete(ABR* T, ABR* t) {
        while (t != T and t->color == BLACK) {
            ABR* p = t->parent;
            if (t == p->left) {
                ABR* f = p->right;   // Fratello
                ABR* ns = f->left;   // Nipote sinistro
                ABR* nd = f->right;  // Nipote destro

                if (f->color == RED) {  // caso 1
                    p->color = RED;
                    f->color = BLACK;
                    rotateLeft(p);  // t viene lasciato in alterato, si passa ai casi 2, 3, 4
                } else {
                    if (ns->color == BLACK && nd->color == BLACK) {
                        f->color = RED;
                        t = p;
                    } else if (ns->color == RED && nd->color == BLACK) {
                        ns->color = BLACK;
                        f->color = RED;
                        rotateRight(f);  // t viene lasciato inalterato, si passa al caso 4
                    } else if (nd->color == RED) {
                        f->color = p->color;
                        p->color = BLACK;
                        nd->color = BLACK;
                        rotateLeft(p);
                        t = T;
                    }
                }
            } else {                 // t == p->right
                ABR* f = p->left;    // Fratello
                ABR* ns = f->left;   // Nipote sinistro
                ABR* nd = f->right;  // Nipote destro

                if (f->color == RED) {  // caso 1
                    p->color = RED;
                    f->color = BLACK;
                    rotateRight(p);  // t viene lasciato in alterato, si passa ai casi 2, 3, 4
                } else {
                    if (ns->color == BLACK && nd->color == BLACK) {
                        f->color = RED;
                        t = p;
                    } else if (ns->color == BLACK && nd->color == RED) {
                        nd->color = BLACK;
                        f->color = RED;
                        rotateLeft(f);  // t viene lasciato inalterato, si passa al caso 4
                    } else if (ns->color == RED) {
                        f->color = p->color;
                        p->color = BLACK;
                        ns->color = BLACK;
                        rotateRight(p);
                        t = T;
                    }
                }
            }
        }
        if (t != NULL) {
            t->color = BLACK;
        }
    }

    static ABR* min(ABR* T) {
        while (T->left != NULL)
            T = T->left;
        return T;
    }
    static ABR* max(ABR* T) {
        while (T->right != NULL)
            T = T->right;
        return T;
    }
    static ABR* successorNode(ABR* t) {  //Statico?
        if (t == NULL)
            return t;
        if (t->right != NULL)
            return min(t->right);
        ABR* p = t->parent;
        while (p != NULL && t == p->right) {
            t = p;
            p = p->parent;
        }
        return p;
    }
    static ABR* predecessorNode(ABR* t) {  //Statico?
        if (t == NULL)
            return t;
        if (t->left != NULL)
            return max(t->left);
        ABR* p = t->parent;
        while (p != NULL && t == p->left) {
            t = p;
            p = p->parent;
        }
        return p;
    }
    void printOrderMode() {
        ABR* u = min(this);
        while (u != NULL) {
            cout << "[" << u->key << ", " << u->value << "]" << endl;
            u = successorNode(u);
        }
    }
    //Override
    static void printPreVisit(ABR* T) {
        if (T != NULL) {
            cout << "[" << T->key << ", " << T->value << ", " << T->color << "]" << endl;
            printPreVisit(T->left);
            printPreVisit(T->right);
        }
    }
    //Override
    static void printBFS(ABR* T) {
        if (T != NULL) {
            Queue<ABR*>* Q = new Queue<ABR*>();
            Q->enqueue(T);
            while (!Q->isEmpty()) {
                ABR* u = Q->dequeue();
                cout << "[" << u->key << ", " << u->value << "]" << endl;
                if (u->left != NULL)
                    Q->enqueue(u->left);
                if (u->right != NULL)
                    Q->enqueue(u->right);
            }
        }
    }

    static void printIndented(const ABR* t) {
        static int depth = 0;
        depth++;
        if (t != NULL) {
            printIndented(t->right);
            print_spaces(depth);
            cout << t->value << endl;
            printIndented(t->left);
        }
        depth--;
    }

    static void print_spaces(int depth) {
        for (int i = 0; i < depth; i++)
            cout << "  ";
    }

    static ABR* rotateLeft(ABR* x) {
        ABR* y = x->right;
        ABR* p = (x->parent != NULL) ? x->parent : NULL;
        x->right = y->left;
        if (y->left != NULL) y->left->parent = x;
        y->left = x;
        x->parent = y;
        y->parent = p;
        if (p != NULL)
            if (p->left == x)
                p->left = y;
            else
                p->right = y;
        return y;
    }
    static ABR* rotateRight(ABR* x) {
        ABR* y = x->left;
        ABR* p = (x->parent != NULL) ? x->parent : NULL;
        x->left = y->right;
        if (y->right != NULL) y->right->parent = x;
        y->right = x;
        x->parent = y;
        y->parent = p;
        if (p != NULL)
            if (p->right == x)
                p->right = y;
            else
                p->left = y;
        return y;
    }
};
#endif