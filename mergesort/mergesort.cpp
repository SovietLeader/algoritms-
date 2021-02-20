#include <vector>
#include <iostream>
using namespace std;


void mergesort(int* b1, int* e1, int n1, int* b2, int* e2, int n2) {
    if (n1 > 1) mergesort(b1, (e1 - n1 / 2), n1 - n1 / 2, (e1 + 1 - n1 / 2), e1, n1 / 2);
    if (n2 > 1) mergesort(b2, (e2 - n2 / 2), n2 - n2 / 2, (e2 + 1 - n2 / 2), e2, n2 / 2);
    int j = 0, i = 0, k = 0;
    vector <int> mas(n1 + n2);
    while (i < n1 && j < n2) {
        if (b1[i] < b2[j]) {
            mas[k] = b1[i];
            i++;
        }
        else {
            mas[k] = b2[j];
            j++;
        }
        k++;
    }
    for (; i < n1; i++, k++) {
        mas[k] = b1[i];
    }
    for (; j < n2; j++, k++) {
        mas[k] = b2[j];
    }
    for (int h = 0; h < n1 + n2; h++) {
        b1[h] = mas[h];
    }

}

int main()
{
    int n; //размер массива
    cin >> n;
    vector <int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    mergesort(&mas[0], (&mas[n - 1 - n / 2]), n - n / 2, (&mas[n - n / 2]), &mas[n - 1], n / 2);
    for (int i = 0; i < n; i++) {
        cout << mas[i] << ' ';
    }
    return 0;
}

