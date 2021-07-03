#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, tmp1, tmp2;

    deque<int> first;
    deque<int> second;
    queue<bool> segments;

    ifstream in("input.txt");
    in >> N;

    for (int i = 0; i < N; i++) {
        in >> tmp1 >> tmp2;
        first.push_back(tmp1);
        second.push_back(tmp2);
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    bool old = true;

    int start = first.front();
    int last = second.back();

    pair<int, int> data = make_pair(-1, -1);

    tmp1 = -1;
    tmp2 = -1;

    for (int i = start; i <= last; i++) {
        while (first.front() == i) {
            first.pop_front();
            segments.push(true);
        }

        while (second.front() == i) {
            second.pop_front();
            segments.pop();
        }

        //cout << i << " " << segments.size();

        //cout << " - FIRST: " << first.front();

        //cout << " - SECOND: " << second.front();

        if (old == true && segments.empty()) {
            //cout << " - starting new sequence";
            old = false;
            tmp1 = i;
        } else if (old == false && !segments.empty()) {
            //cout << " - ending sequence";
            old = true;
            tmp2 = i;

            if (data.first == -1) {
                data = make_pair(tmp1, tmp2);
            } else {
                if (data.second - data.first < tmp2 - tmp1) {
                    data = make_pair(tmp1, tmp2);
                }
            }
            // cout << tmp1 << " " << tmp2 << endl;
        }
        //cout << endl;
    }

    ofstream out("output.txt");

    /*for(int i = 0; i < data.size(); i++) {
        cout << data.at(i).first << " " << data.at(i).second << endl;
    }*/

    if (data.first == -1) {
        out << 0;
    } else {
        out << data.first << " " << data.second;
    }

    return 0;
}