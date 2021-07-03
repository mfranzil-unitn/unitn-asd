#include <fstream>
#include <iostream>
#include <vector>
#include "ClassiLollo/binarytree.h"

using namespace std;

void reverse(vector<char> pre, vector<char> in, int dir, BinaryTree<char> *t);

int main() {
    BinaryTree<char> *t = new BinaryTree<char>('t');
    vector<char> pre = {'A', 'E', 'B', 'F', 'G', 'C', 'D', 'I', 'H'};
    vector<char> in = {'B', 'E', 'G', 'F', 'C', 'A', 'D', 'H', 'I'};

    reverse(pre, in, 0, t);

    BinaryTree<char>::printIndented(t);

    return 0;
}

void reverse(vector<char> pre, vector<char> in, int dir, BinaryTree<char> *t) {
    if (pre.size() == 1 && in.size() == 1) {
        if (dir == 0) {
            t->insertLeft(pre.at(0));
        } else {
            t->insertRight(pre.at(0));
        }
    } else if (pre.size() == 0 && in.size() == 0) {
        return;
    } else {
        char first = pre.at(0);
        int pos = -1;

        for (int i = 0; i < in.size(); i++) {
            if (in.at(i) == first) {
                pos = i;
                break;
            }
        }

        if (dir == 0) {
            t->insertLeft(first);
            t = t->getLeft();
        } else {
            t->insertRight(first);
            t = t->getRight();
        }

        vector<char> preL(pre.begin() + 1, pre.begin() + pos + 1);
        vector<char> preR(pre.begin() + pos + 1, pre.end());

        vector<char> inL(in.begin(), in.begin() + pos);
        vector<char> inR(in.begin() + pos + 1, in.end());

        reverse(preL, inL, 0, t);
        reverse(preR, inR, 1, t);
    }
}