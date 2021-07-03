#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <vector>
#include "graphNode.h"
using namespace std;

template <class Item>
class Graph {
   protected:
    vector<GraphNode<Item>*> G;
    bool oriented;

   public:
    static const int INFINITY = -1;
    Graph(bool oriented) {
        this->oriented = oriented;
    }
    ~Graph() {
        for (GraphNode<Item>* u : this->G)
            delete u;
        //cout << "Oggetto Graph rimosso!" << endl;
    }
    void insertNode(GraphNode<Item>* u) {
        this->G.push_back(u);
    }
    void insertEdge(int u, int v) {
        this->G[u]->insertAdj(v);
        if (!this->oriented) this->G[v]->insertAdj(u);
    }
    void deleteNode(int u) {
        this->G.erase(this->G.begin() + u);
        for (int i = 0; i < this->G.size(); i++)
            this->G[i]->deleteAdj(u);
    }
    void deleteEdge(int u, int v) {
        this->G[u]->deleteAdj(v);
        this->G[v]->deleteAdj(u);
    }
    int getV() {
        return this->G.size();
    }
    GraphNode<Item>* getNode(int i) {
        return this->G[i];
    }
    static void erdos(Graph& G, int r, int erdos[], GraphNode<Item>* p[]) {
        queue<int> S;
        S.push(r);
        for (int u = 0; u < G.getV(); u++)
            erdos[u] = INFINITY;
        erdos[r] = 0;
        p[r] = NULL;
        while (!S.empty()) {
            int u = S.front();
            S.pop();
            for (int v : G.getNode(u)->getAdj())
                if (erdos[v] == INFINITY) {
                    erdos[v] = erdos[u] + 1;
                    p[v] = G.getNode(u);
                    S.push(v);
                }
        }
    }
};
#endif