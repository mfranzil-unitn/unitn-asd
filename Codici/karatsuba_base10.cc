#include <cmath>
#include <iostream>
#include <vector>

// Not working

using namespace std;

int MAX_SIZE = 32;

int karatsuba(int x, int y, int n);

int main() {
    int a = 1000;
    int b = 100;

    int prod = karatsuba(a, b, 4);
    cout << prod;
    return 0;
}

int karatsuba(int x, int y, int n) {
    if (n == 1) {
        return x * y;
    } else {
        int a = floor(x / pow(10, n / 2));
        int b = x % ((int)pow(10, n / 2));
        int c = floor(y / pow(10, n / 2));
        int d = y % ((int)pow(10, n / 2));

        int A1 = karatsuba(a, c, n / 2);
        int A3 = karatsuba(b, d, n / 2);
        int m = karatsuba(a + b, c + d, n / 2);

        int A2 = m - A1 - A3;

        return A1 * pow(10, n) + A2 * pow(10, n / 2) + A3;
    }
}