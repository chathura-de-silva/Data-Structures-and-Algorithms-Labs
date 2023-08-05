#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void RecursiveMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        RecursiveMergeSort(arr, l, m);
        RecursiveMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void IterativeMergeSort(int arr[], int n) {
    int curr_size;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);
        }
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));  // Initialize random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generate a random integer between 0 and 99
    }
}

int main() {

    const int n = 30000;  // Size of the array$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
    int arr[n],arr2[n];
   generateRandomArray(arr, n);

    auto start = high_resolution_clock::now();
    RecursiveMergeSort(arr,0,n+1);
    auto stop = high_resolution_clock::now();
//        printArray(arr,n);


    auto duration = duration_cast<microseconds>(stop - start);  // Calculate the duration
    cout << "Execution time: " << duration.count() << " microseconds." << endl;

//
//    generateRandomArray(arr2, n);
//    auto begin= high_resolution_clock::now();
//    IterativeMergeSort(arr2,n);
//    auto end = high_resolution_clock::now();
//
//    auto duration1 = duration_cast<microseconds>(end - begin);  // Calculate the duration
//    cout << "Execution time: " << duration1.count() << " microseconds." << endl;


//        printArray(arr,n);
    return 0;
}
