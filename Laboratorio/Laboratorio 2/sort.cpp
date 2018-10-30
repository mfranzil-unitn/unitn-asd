#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void merge(vector<int>& a, int first, int last, int mid);
void mergeSort(vector<int>& a, int first, int last);

vector<int> b;

int main() {
    int N, tmp;
    vector<int> data;

    ifstream in("input.txt");
    in >> N;

    for (int i = 0; i < N; i++) {
        in >> tmp;
        data.push_back(tmp);
    }

    b.resize(N);

    mergeSort(data, 0, N - 1);

    ofstream out("output.txt");
    for (int i = 0; i < N; i++) {
        out << data.at(i) << " ";
    }
    
    return 0;
}

void merge(vector<int>& a, int first, int last, int mid) {
    int i = first, j = mid + 1, k = first, h;
    while ((i <= mid) && (j <= last)) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    j = last;

    for (h = mid; h >= i; h--) {
        a[j] = a[h];
        j--;
    }
    for (j = first; j <= k - 1; j++) {
        a[j] = b[j];
    }
}

void mergeSort(vector<int>& a, int first, int last) {
    if (first < last) {
        int mid = floor((first + last) / 2.0);
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, last, mid);
    }
}