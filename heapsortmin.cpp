#include <iostream>
using namespace std;

int A[100];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int n, int i) {
    int min = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && A[l] < A[min]) {
        min = l;
    }
    if (r < n && A[r] < A[min]) {
        min = r;
    }
    if (min != i) {
        swap(A[i], A[min]);
        heapify(A, n, min);
    }
}

void heapsort(int A[], int n) {
    //2i + 1 = n - 1 -> i = n / 2 - 1
    for (int i = (n/2 - 1); i >= 0; i--) {
            heapify(A, n, i);
            }

        for (int a = n -1; a > 0; a--) {
            swap(A[0], A[a]);
        for (int j = 0; j < n; j++) {
             cout << A[j] << " ";
             }
             cout << endl;
            for (int i = (n/2 -1); i>=0; i--){
            heapify(A, a, i);
            }

            
        }
        
}



void printA(int A[], int n){
    for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
    }
    cout << endl;
 }
int main() {
    int n, i;
    cout << "Nhap so phan tu mang A: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Nhap A[" << i <<"]" << " ";
        cin >> A[i];
    }

    cout << "Mang A:";
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    heapsort(A,n);
    cout << "Mang da sap xep: ";
    printA(A,n);
    
} 