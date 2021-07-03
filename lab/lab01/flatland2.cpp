#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct triangle {
    int id;
    char dir;
};

void work(vector<triangle> &triangoli, int x);

int main() {
    int N, rnd;
    bool check = true;
    vector<triangle> triangoli, temp;
    set<int> output;
    triangle tmp;
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;
    for (int i = 0; i < N; i++) {
        in >> tmp.dir;
        tmp.id = i;
        triangoli.push_back(tmp);
    }

    srand(time(NULL));

    for (int j = 0; j < (N < 180 ? 625 : 410); j++)
        for (int i = 1; i < N - 1; i++) {
            temp.assign(triangoli.begin(), triangoli.end());
            //cout << "SCEGLIE " << i << endl;

            /*for(triangle t : temp)
				cout << "[" << t.id << ", " << t.dir << "]" << endl;
			cout << endl;*/

            while (temp.size() > 2)
                if (temp.size() == 3) {
                    work(temp, 1);
                    output.insert(temp.at(0).id);
                    //cout << "[" << temp.at(0).id << ", " << temp.at(0).dir << "]" << endl;
                } else if (i >= temp.size() - 1) {
                    //cout << "CAMBIA SCELTA A " << temp.size()/2 << endl;
                    work(temp, temp.size() / 2);
                } else {
                    rnd = rand() % (temp.size() - 2) + 1;
                    //cout << "CAMBIA SCELTA A " << rnd << endl;
                    work(temp, rnd);
                }
            temp.clear();
        }

    out << output.size() << endl;
    for (int v : output)
        out << v << " ";
    out << endl;

    return 0;
}

void work(vector<triangle> &triangoli, int x) {
    triangle tmp;
    tmp = triangoli.at(x);
    if (tmp.dir == 's')
        triangoli.erase(triangoli.begin() + x - 1, triangoli.begin() + x + 1);
    else
        triangoli.erase(triangoli.begin() + x, triangoli.begin() + x + 2);
}
