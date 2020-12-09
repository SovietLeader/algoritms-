#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

void swap(int& a, int& b) {
    int s;
    s = a;
    a = b;
    b = s;
}

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

int main() {
    int n, swap, check;
    ifstream F;
    F.open("input.txt");
    F >> n;


    vector <int> mas(n);
    for (int i = 0; i < n; i++) {
        F >> mas[i];
    }


    int n1 = mas.size();
    hsort(mas, n1);


    ofstream F2;
    F2.open("output.txt");
    ofstream out("output.txt");


    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }
    cout << endl;
    mas.clear();
}

