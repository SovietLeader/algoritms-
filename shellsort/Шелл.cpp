#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

void sorti(vector<int>& mas, int key, int ind) {
    int swap;

    for (int i = key + ind; i < mas.size(); i += key) {
        if (mas[i] < mas[i - key]) {
            swap = mas[i];
            mas[i] = mas[i - key];
            mas[i - key] = swap;
            for (int j = i - key; j >= key; j -= key) {
                if (mas[j] < mas[j - key]) {
                    swap = mas[j];
                    mas[j] = mas[j - key];
                    mas[j - key] = swap;
                }
                else break;
            }
        }
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
 
    check = (int)log((float)n + 1) / log((float)2);
    for (int i = 1; i < n; i++) {
        swap = pow(2, check) - 1;
        if ((check > 0) && (swap > 0)) {
            for (int j = 0; j < n - swap; j++) sorti(mas, swap, j);
        }
        check--;
    }
    ofstream F2;
    F2.open("output.txt");
    ofstream out("output.txt");


    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }
    cout << endl;
    mas.clear();
}
