#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

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

void quicksort(vector<int>& mas, int low, int high) {
    if (low < high) {
        int p = part(mas, low, high);
        quicksort(mas, low, p - 1);
        quicksort(mas, p + 1, high);
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

    quicksort(mas, 0, n - 1);

    ofstream F2;
    F2.open("output.txt");
    ofstream out("output.txt");


    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }
    cout << endl;
    mas.clear();
}

