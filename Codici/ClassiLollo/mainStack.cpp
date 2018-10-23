#include<iostream>
#include "Stack.h"
using namespace std;

int stampaMenu();

int main(){
    Stack<int>* pila = new Stack<int>();
    int scelta, n;

    do{
        scelta = stampaMenu();
        switch(scelta){
            case 1:
                cout << "New element: ";
                cin >> n;
                pila->push(n);
                break;
            case 2:
                if(!pila->isEmpty())
                    cout << "Pop element: " << pila->pop() << endl;
                else
                    cout << "Stack empty!" << endl;
                break;
            case 3:
                if(!pila->isEmpty())
                    cout << "Top element: " << pila->top() << endl;
                else
                    cout << "Stack empty!" << endl;
                break;
            case 4:
                if(!pila->isEmpty())
                    pila->print();
                else
                    cout << "Stack empty!" << endl;
                break;
            case 5:
                break;
            default:
                cout << "Comand not found!" << endl;
        }
    }while(scelta != 5);
    
    delete pila;
    return 0;
}

int stampaMenu(){
    int s;
    cout << endl << "1. Push element" << endl;
    cout << "2. Pop element" << endl;
    cout << "3. Top element" << endl;
    cout << "4. Print all elements" << endl;
    cout << "5. Quit" << endl;
    cout << "Choose: ";
    cin >> s;
    return s;
}