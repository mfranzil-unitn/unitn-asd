#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Component {
    int soldier;
    int index;
    int value;
    pair<int, int> coord;
};

struct Soldier {
    int component;
    pair<int, int> coord;
};

int solve();
int manhattan(pair<int, int> soldier, pair<int, int> component);

vector<Component*> components;
vector<Soldier*> soldiers;
pair<int, int> target;

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
    srand(time(0));
    int C, S;
    in >> C >> S;

    for (int i = 0; i < C; i++) {
        int x, y;
        in >> x >> y;

        Component* tmp = new Component();
        tmp->soldier = INT32_MAX;
        tmp->value = INT32_MAX;
        tmp->index = i;
        tmp->coord = make_pair(x, y);
        components.push_back(tmp);
    }

    for (int i = 0; i < S; i++) {
        int x, y;
        in >> x >> y;

        Soldier* tmp = new Soldier();
        tmp->component = INT32_MAX;
        tmp->coord = make_pair(x, y);
        soldiers.push_back(tmp);
    }

    in >> target.first >> target.second;

    cout << solve();
}

int solve() {
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> priorities;
    set<int> assigned;

    // cout << components.size() << " " << soldiers.size();

    for (int i = 0; i < components.size(); i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tmp;
        for (int j = 0; j < soldiers.size(); j++) {
            tmp.push(make_pair(manhattan(soldiers.at(j)->coord, components.at(i)->coord), j));  // first = valore, secondo = soldato
        }
        tmp.push(make_pair(manhattan(target, components.at(i)->coord), -1));
        priorities.push_back(tmp);
    } /*

    for (int i = 0; !priorities.empty(); i++) {
        for (int j = 0; !priorities.at(i).empty(); j++) {
            cout << priorities.at(i).top().first << " (" << priorities.at(i).top().second << ") ";
            priorities.at(i).pop();
        }
        cout << endl;
    }*/

    for (int k = 0; k < priorities.size(); k++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> current_queue = priorities.at(k);

        pair<int, int> min_dist = current_queue.top();  // pair di distanza, soldato
                                                        // cout << min_dist.first << " " << min_dist.second << endl;
        current_queue.pop();

        //if (assigned.count(min_dist.second)) {
        int soldatoAssegnato = min_dist.second;
        /*  cout << components.at(14)->soldier << endl
             << endl;
        if (assigned.count(soldatoAssegnato) && min_dist.second != -1) {
            cout << "Iteration starting from" << k << " - soldato " << soldatoAssegnato << endl;
            cout << "Soldato3 ha " << soldiers.at(3)->component << endl;
        }*/
        while (assigned.count(soldatoAssegnato) && min_dist.second != -1) {
            int componenteGiaAssegnata = soldiers.at(min_dist.second)->component;
            int componenteCorrente = k;

            int distanzaGiaAssegnata = components.at(componenteGiaAssegnata)->value;
            int distanzaCorrente = min_dist.first;

            int secondaGiaAssegnata = priorities.at(componenteGiaAssegnata).top().first;
            int secondaCorrente = priorities.at(componenteCorrente).top().first;

            if (secondaCorrente + componenteGiaAssegnata >= secondaGiaAssegnata + componenteCorrente) {
                min_dist = current_queue.top();
                current_queue.pop();
                soldatoAssegnato = min_dist.second;
            } else {
                pair<int, int> giaAssegnataSeconda = priorities.at(componenteGiaAssegnata).top();
                priorities.at(componenteGiaAssegnata).pop();

                assigned.erase(soldatoAssegnato);
                soldiers.at(soldatoAssegnato)->component = INT32_MAX;

                soldatoAssegnato = giaAssegnataSeconda.second;

                if (soldatoAssegnato != -1) {
                    assigned.insert(giaAssegnataSeconda.second);
                    soldiers.at(giaAssegnataSeconda.second)->component = componenteGiaAssegnata;
                }
                components.at(componenteGiaAssegnata)->soldier = giaAssegnataSeconda.second;
                components.at(componenteGiaAssegnata)->value = giaAssegnataSeconda.first;
            }

            cout << soldatoAssegnato << " C(" << componenteGiaAssegnata << " " << secondaGiaAssegnata << endl;
        }

        if (min_dist.second != -1) {
            assigned.insert(min_dist.second);
            soldiers.at(min_dist.second)->component = k;
        }
        components.at(k)->soldier = min_dist.second;
        components.at(k)->value = min_dist.first;
    }

    int sum = 0;
    for (int i = 0; i < components.size(); i++) {
        sum += components.at(i)->value;
        cout << components.at(i)->index << " S(" << components.at(i)->soldier << ") V(" << components.at(i)->value << ")" << endl;
    }

    return sum;
} /*
}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> f;
    for (int k = 0; k < priorities.size(); k++) {
        int size = priorities.at(k).size();
        for (int i = 0; i < size; i++) {
            pair<int, int> p = priorities.at(k).top();
            f.push(make_pair(p.first,make_pair(p.second, k))); // soldato componente valore
            priorities.at(k).pop();
             out << p.first << " (S" << p.second << ") ";
        }
        out << "\n";
    }}

    int size = f.size();

    for (int i = 0; i < size; i++) {
        pair<int, pair<int, int>> p = f.top();
        f.pop();
        out << p.first  << " (S" << p.second.first << " C" <<  p.second.second << ") ";
    }
}

void solve1(){
    int mini = INT32_MAX;
    for(int i=0; i < components.size(); i++){
         int dist = manhattan(soldiers.at(j)->coord, components.at(i)->coord);
            mini = min(dist, mini);
            if (dist == mini) {
                components.at(i)->value = dist;
            }
    }

    int tot =0;
    for(int i=0; i < components.size(); i++){

    }


}*/
int manhattan(pair<int, int> soldier, pair<int, int> component) {
    return abs(soldier.first - component.first) + abs(soldier.second - component.second) +
           abs(component.first - target.first) + abs(component.second - target.second);
}