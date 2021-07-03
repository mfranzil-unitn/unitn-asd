#include <time.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace sort {
void merge(vector<int>& a, int first, int last, int mid);
void mergeSort(vector<int>& a, int first, int last);
void insertionSort(vector<int>& a);
void selectionSort(vector<int>& a);
int min(vector<int> a, int start, int end);
}  // namespace sort

vector<int> b;

int main() {
    clock_t start, end;
    double cpu_time_used;
    vector<int> arr1, arr2, arr3;

    do {
        for (int i = 0; i < 10000; i++) {
            int rnd = rand() % 10000;
            arr1.push_back(rnd);
            arr2.push_back(rnd);
            arr3.push_back(rnd);
            b.push_back(0);
        }
        start = clock();
        sort::mergeSort(arr1, 0, arr1.size() - 1);
        end = clock();
        cout << arr1.size() << " MergeSort: " << ((double)1000 * (end - start)) / CLOCKS_PER_SEC << "\n";

        start = clock();
        sort::insertionSort(arr2);
        end = clock();
        cout << arr2.size() << " InsertionSort: " << ((double)1000 * (end - start)) / CLOCKS_PER_SEC << "\n";

        start = clock();
        sort::selectionSort(arr3);
        end = clock();
        cout << arr3.size() << " SelectionSort: " << ((double)1000 * (end - start)) / CLOCKS_PER_SEC << "\n\n";

        /*for (int i = 0; i < arr2.size(); i++) {
            cout << arr2[i] << " ";
        }*/
    } while (true);
}

void sort::merge(vector<int>& a, int first, int last, int mid) {
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

void sort::mergeSort(vector<int>& a, int first, int last) {
    if (first < last) {
        int mid = floor((first + last) / 2.0);
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, last, mid);
    }
}

void sort::insertionSort(vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int temp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

void sort::selectionSort(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        int min = sort::min(a, i, a.size() - 1);
        if (a[i] != a[min]) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int sort::min(vector<int> a, int start, int end) {
    int min = start;
    for (int j = start + 1; j <= end; j++) {
        if (a[j] < a[min]) {
            min = j;
        }
    }
    return min;
}