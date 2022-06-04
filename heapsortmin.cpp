#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// vector<int> A;
int A[6];
int i, n, a;
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

void swapMin(int A[], int n){
    for(int i =0; i < n/2; i++) {
        a = n - i - 1;
            swap(A[i], A[a]);
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
    // cout << "Nhap so phan tu mang A: ";
    // cin >> n;
    // for (i = 0; i < n; i++) {
    //     cout << "Nhap A[" << i <<"]" << " ";
    //     cin >> A[i];
    // }
    // FILE *fp = fopen("E:\\heapsortmin.txt", "r");
    // if (fp == NULL) {
    //     cout <<"CAN'T OPEN FILE!!!";
    // }
    // int k = 0;
    // cout << "XUAT N" << n << " ";
    // cout << "Mang A:";
    // while (fscanf(fp, "%d", &A[k]) != EOF) {
    //     k++;
       
    //     int n = sizeof(A) / sizeof(A[0]);
        
    //         for (i = 0; i < n; i++) {
    //             cout << A[i] << " ";
    //         }
    // }
    // cout << "XUAT N" << n << " ";
    // fclose (fp);
    
    // doc file txt
    ifstream file;
    file.open("heapsortmin.txt");   // mo file de doc
    file >> n;
    cout << "so phan tu mang A:" << n << endl;
     for (int i = 0; i <n; i++)
    { 
        file >> A[i];
    }
    file.close();
    system("pause");


    cout << endl;
    heapsort(A,n);
   
    swapMin(A,n);
    
    

    //xuat file txt
    ofstream file1 ("sapxep.txt");
    cout << "Mang da sap xep: ";
    printA(A,n);
    for(int i = 0; i < n; i++) {
        file1 << A[i] << " ";
    }
    file1.close();
} 