#include<iostream>
#include "ABR.h"
using namespace std;

int stampaMenu();

int main(){
    ABR<int>* dictionary = NULL;
    ABR<int>* t;
    int scelta, k, v;
    
    do{
        scelta = stampaMenu();
        switch(scelta){
            case 1:
                cout << "Key: ";
                cin >> k;
                cout << "New value: ";
                cin >> v;
                dictionary = ABR<int>::insertNode(dictionary, k, v, true);
                break;
            case 2:
                cout << "Key: ";
                cin >> k;
                if(dictionary != NULL)
                    dictionary = ABR<int>::removeNode(dictionary, k);
                else
                    cout << "Dictionary empty!" << endl;
                break;
            case 3:
                cout << "Key: ";
                cin >> k;
                t = (dictionary != NULL) ? ABR<int>::lookupNode(dictionary, k) : NULL;
                if(t != NULL)
                    cout << "Value: " << t->getValue() << endl;
                else
                    cout << "No value found!" << endl;
                break;
            case 4:
                if(dictionary != NULL){
                    cout << "PREVISIT" << endl;
                    ABR<int>::printPreVisit(dictionary);
                    cout << endl << "BFS PRINT" << endl;
                    ABR<int>::printBFS(dictionary);
                    cout << endl << "ORDER VISIT" << endl;
                    dictionary->printOrderMode();
                }else
                    cout << "Dictionary empty!" << endl;
                break;
            case 5:
                break;
            default:
                cout << "Comand not found!" << endl;
        }
    }while(scelta != 5);
    
    if(dictionary != NULL)
        delete dictionary;
    return 0;
}

int stampaMenu(){
    int s;
    cout << endl << "1. Insert key-value node" << endl;
    cout << "2. Remove key-value node" << endl;
    cout << "3. Search value of a key" << endl;
    cout << "4. Print all elements in order" << endl;
    cout << "5. Quit" << endl;
    cout << "Choose: ";
    cin >> s;
    return s;
}