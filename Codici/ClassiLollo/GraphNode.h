#ifndef _GRAPHNODE_H
#define _GRAPHNODE_H
#include<iostream>
#include<vector>
using namespace std;

template<class Item>
class GraphNode{
    protected:
        Item value;
        vector<int> adj;
        bool visited;
    public:
        GraphNode(Item v){
            this->value = v;
        }
        ~GraphNode(){
            //cout << "Oggetto GraphNode rimosso!" << endl;
        }
        void insertAdj(int v){
            this->adj.push_back(v);
        }
        void deleteAdj(int v){
            for(int i = 0; i < this->adj.size(); i++)
                if(adj.at(i) == v)
                    this->adj.erase(this->adj.begin()+i);
        }
        vector<int> getAdj(){
            return this->adj;
        }
        Item getValue(){
            return this->value;
        }
};
#endif