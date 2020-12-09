#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void heapify(vector<int>& A, int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if (left <= n - 1) {
        if (A[left] > A[largest]) largest = left;
    }

    if (right <= n - 1) {
        if (A[right] > A[largest]) largest = right;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, largest, n);
    }

}

void create_heap(vector<int>& A) {
    for (int i = A.size() / 2 - 1; i >= 0; i--) {
        heapify(A, i, A.size() - 1);
    }
}

void hsort(vector<int>& A, int n) {
    create_heap(A);
    for (int i = n - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapify(A, 0, i);
    }

}


int part(vector<int>& mas, int low, int high) {
    int pivot = mas[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (mas[j] <= pivot) {
            swap(mas[i], mas[j]);
            i++;
        }
        swap(mas[i], mas[high]);
    }
    return i;
}


void introsort(vector<int>& mas, int low, int high, int depth) {

    if (mas.size() <= 1) return;
    else if (depth == 0) hsort(mas, mas.size());
    else
        if (low < high) {
            int p = part(mas, low, high);
            introsort(mas, low, p - 1, depth - 1);
            introsort(mas, p + 1, high, depth - 1);
        }
}

void sort(vector<int>& mas) {
    int maxdepth = log(mas.size()) * 2;
    introsort(mas, 0, mas.size()-1, maxdepth);
}

int main() {
    int n, swap, check;
    ifstream F;
    F.open("input.txt");
    F >> n;


    vector <int> mas(n);
    for (int i = 0; i < n; i++) {
        F >> mas[i];
    }

    sort(mas);

    ofstream F2;
    F2.open("output.txt");
    ofstream out("output.txt");


    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }
    cout << endl;
    mas.clear();
}

