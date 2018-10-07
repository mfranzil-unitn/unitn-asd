#include <cmath>
#include <iostream>
#include <vector>

namespace coppia {
bool coppia1(std::vector<int>& A, int v);
bool coppia15(std::vector<int>& A, int v);
}  // namespace coppia

namespace sort {
void merge(std::vector<int>& a, int first, int last, int mid);
void mergeSort(std::vector<int>& a, int first, int last);
}  // namespace sort

std::vector<int> b;

int main() {
    std::vector<int> A = {4, 5, 9, 1, 29, 39, 59, 29, 10, 1, 2, 5, 2, 5};
    int v = 88;

    bool res = coppia::coppia15(A, v);
    std::cout << (res ? "True" : "False") << "\n";
}

bool coppia::coppia1(std::vector<int>& A, int v) {
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = i + 1; j < A.size(); j++) {
            if (A[i] + A[j] == v) {
                return true;
            }
        }
    }
    return false;
}

bool coppia::coppia15(std::vector<int>& A, int v) {
    int start = 0, end = A.size() - 1, mid = (A.size() - 1) / 2;
    sort::mergeSort(A, start, end);
    for (int i = start; i < mid;) {
        for (int j = end; j >= mid;) {
            if (A[i] + A[j] == v) {
                return true;
            } else if (A[i] + A[j] < v) {
                i++;
            } else {
                j++;
            }
        }
    }
    return false;
}

void sort::merge(std::vector<int>& a, int first, int last, int mid) {
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

void sort::mergeSort(std::vector<int>& a, int first, int last) {
    if (first < last) {
        int mid = floor((first + last) / 2.0);
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, last, mid);
    }
}