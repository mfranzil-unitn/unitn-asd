#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//map<pair<int, int>, int> DP;
vector<int> DP;
vector<pair<int, int>> PV;

int N, C;
int p, v;

ifstream in("input.txt");
ofstream out("output.txt");

// int zaino(int i, int c);

int main() {
    in >> C >> N;

    for (int i = 0; i < N; i++) {
        in >> p >> v;
        PV.push_back(make_pair(p, v));
    }

    DP.resize(C + 1, -1);
    DP.at(0) = 0;

    for (int i = 0; i < N; i++) {
        p = PV.at(i).first;
        v = PV.at(i).second;
        for (int i = C; i - p >= 0; i--) {
            if (DP.at(i - p) > -1) {
                DP.at(i) = max(DP.at(i), DP.at(i - p) + v);
            }
        }
    }

    int res = -1;
    for (int c = 0; c <= C; c++) {
        res = max(res, DP.at(c));
    }

    out << res;

    return 0;
}

/*
int zaino(int i, int c) {
    //cout << "Calling zaino(" << i << ", " << c << ")" << endl;
    if (c < 0) {
        return -1000;
    } else if (i == 0 || c == 0) {
        return 0;
    } else {
        if (DP.at(i - 1).at(c - 1) == -1) {
            DP.at(i - 1).at(c - 1) = max(zaino(i - 1, c), zaino(i - 1, c - PV.at(i - 1).first) + PV.at(i - 1).second);
        }
        return DP.at(i - 1).at(c - 1);
    }
}

int zaino(int i, int c) {
    //cout << "Calling zaino(" << i << ", " << c << ")" << endl;
    if (c < 0) {
        return -1000;
    } else if (i == 0 || c == 0) {
        return 0;
    } else {
        pair<int, int> coppia = make_pair(i, c);
        if (DP.count(coppia) == 0) {
            DP.insert(make_pair(coppia, max(zaino(i - 1, c),
                                            zaino(i - 1, c - PV.at(i - 1).first) + PV.at(i - 1).second)));
        }
        return DP.at(coppia);
    }
}*/