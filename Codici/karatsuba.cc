#include <cmath>
#include <iostream>
#include <vector>

// Not working

using namespace std;

int MAX_SIZE = 32;

vector<bool> karatsuba(vector<bool> x, vector<bool> y, int n);
vector<bool> sum(vector<bool> a, vector<bool> b);
vector<bool> complement(vector<bool> vect);
vector<bool> shift(vector<bool> vect, int shift);
void print(vector<bool> vect);
vector<bool> makeSize(vector<bool> vect);
int makeEqualLength(vector<bool> a, vector<bool> b);

int main() {
    vector<bool> a = {1, 0, 1, 0};
    vector<bool> b = {0, 1, 1, 0};

    vector<bool> prod = karatsuba(a, b, a.size());
    print(prod);
    return 0;
}

vector<bool> karatsuba(vector<bool> x, vector<bool> y, int n) {
    if (n == 1) {
        vector<bool> res;
        res.push_back(x[x.size() - 1] * y[y.size() - 1]);
        return res;
    } else {
        vector<bool> a(x.begin(), x.begin() + x.size() / 2);
        vector<bool> b(x.begin() + x.size() / 2, x.end());

        vector<bool> c(y.begin(), y.begin() + y.size() / 2);
        vector<bool> d(y.begin() + y.size() / 2, y.end());

        vector<bool> A1 = karatsuba(a, c, n / 2);
        vector<bool> A3 = karatsuba(b, d, n / 2);
        vector<bool> m = karatsuba(sum(a, b), sum(c, d), n / 2);

        vector<bool> A2 = sum(sum(m, complement(A1)), complement(A3));  // m - A1 - A3;

        return sum(sum(shift(A1, n), shift(A2, n / 2)), A3);
    }
}

int makeEqualLength(vector<bool> a, vector<bool> b) {
    if (a.size() == b.size()) {
        return a.size();
    } else if (a.size() > b.size()) {
        int offset = a.size() - b.size();
        for (int i = 0; i < offset; i++) {
            b.insert(b.begin(), 0);
        }
        return a.size();
    } else {
        int offset = b.size() - a.size();
        for (int i = 0; i < offset; i++) {
            a.insert(a.begin(), 0);
        }
        return a.size();
    }
}

vector<bool> shift(vector<bool> vect, int shift) {
    for (int i = 0; i < shift; i++) {
        vect.push_back(0);
        vect.erase(vect.begin());
    }
    return vect;
}

vector<bool> complement(vector<bool> vect) {
    vect = makeSize(vect);

    //print(vect);
    vector<bool> one = {1};
    vect = sum(vect, one);
    //print(vect);

    for (int i = 0; i < vect.size(); i++) {
        vect[i] = !vect[i];
    }

    //print(vect);
    //cout << "\n\n";
    return vect;
}

void print(vector<bool> vect) {
    vect = makeSize(vect);
    int res = 0;
    cout << "Binary: ";
    for (int i = 0; i < vect.size(); i++) {
        res += vect[i] * pow(2, MAX_SIZE - i - 1);
        cout << vect[i];
    }
    cout << "\nDecimal: " << res << "\n";
}

vector<bool> makeSize(vector<bool> vect) {
    int size = vect.size();
    if (size < MAX_SIZE) {
        for (int i = 0; i < (MAX_SIZE - size); i++) {
            vect.insert(vect.begin(), 0);
        }
    }
    return vect;
}

vector<bool> sum(vector<bool> a, vector<bool> b) {
    vector<bool> result;
    bool aBit, bBit;

    int carry = 0;

    int size = makeEqualLength(a, b);
    cout << "\nVettori:\n";
    print(a);
    print(b);

    for (int i = size - 1; i >= 0; i--) {
        aBit = a[i];
        bBit = b[i];
        int sum = ((int)aBit) + ((int)bBit) + ((int)carry);
        if (sum == 2) {
            carry = 1;
            sum = 1;
        } else {
            carry = 0;
        }
        result.insert(result.begin(), (bool) sum);
    }

    result.insert(result.begin(), (bool)carry);

    print(result);

    return result;
}