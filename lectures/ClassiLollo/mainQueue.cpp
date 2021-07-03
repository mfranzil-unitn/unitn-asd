#include <iostream>
#include "Queue.h"
using namespace std;

int stampaMenu();

int main() {
    Queue<int>* coda = new Queue<int>();
    int scelta, n;

    do {
        scelta = stampaMenu();
        switch (scelta) {
            case 1:
                cout << "New element: ";
                cin >> n;
                coda->enqueue(n);
                break;
            case 2:
                if (!coda->isEmpty())
                    cout << "Dequeue element: " << coda->dequeue() << endl;
                else
                    cout << "Queue empty!" << endl;
                break;
            case 3:
                if (!coda->isEmpty())
                    cout << "Top element: " << coda->top() << endl;
                else
                    cout << "Queue empty!" << endl;
                break;
            case 4:
                if (!coda->isEmpty())
                    coda->print();
                else
                    cout << "Queue empty!" << endl;
                break;
            case 5:
                break;
            default:
                cout << "Comand not found!" << endl;
        }
    } while (scelta != 5);

    delete coda;
    return 0;
}

int stampaMenu() {
    int s;
    cout << endl
         << "1. Enqueue element" << endl;
    cout << "2. Dequeue element" << endl;
    cout << "3. Top element" << endl;
    cout << "4. Print all elements" << endl;
    cout << "5. Quit" << endl;
    cout << "Choose: ";
    cin >> s;
    return s;
}