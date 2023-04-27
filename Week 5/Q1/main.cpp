#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Printing array is not needed. Included just to test whether the sorting is happening or not.
void printArray(vector<int>arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void generateRandomArray(vector<int>&array, int n) {
    srand(time(NULL));  // Initialize random number generator
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 100);  // Generate a random integer between 0 and 99
    }
}

int partition(vector<int>&array, int start, int end){
    int pivot = array[end];
    int i = start-1;
    for (int j=start; j<end ; j++){
        if(array[j]<=pivot){
            i++;
            int temp1 = array[i];
            array[i]=array[j];
            array[j]=temp1;
        }
    }
    int temp2 = array[i+1];
    array[i+1]=array[end];
    array[end] = temp2;
    return i+1;
}

//void quicksort(vector<int>&array, int start, int end ){
//    if (start<end){
//        int pivot_index = partition(array,start,end);
//        quicksort(array,start,pivot_index -1);
//        quicksort(array,pivot_index+1,end);
//    }
//}

void quicksort(vector<int>& array, int start, int end ){
    int stack[end - start + 1];
    int top_element = -1;
    stack[++top_element] = start;
    stack[++top_element] = end;

    while (top_element >= 0) {
        end = stack[top_element--];
        start = stack[top_element--];

        int pivot_index = partition(array, start, end);

        if (pivot_index - 1 > start) {
            stack[++top_element] = start;
            stack[++top_element] = pivot_index - 1;
        }

        if (pivot_index + 1 < end) {
            stack[++top_element] = pivot_index + 1;
            stack[++top_element] = end;
        }
    }
}

int main() {
    vector<int> testing_array;
    int length = 25000;
    generateRandomArray(testing_array,length);

//    Time is calculated exclusively for the sorting process.
    auto start = high_resolution_clock::now();
    quicksort(testing_array,0,length-1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);  // Calculate the duration
    cout << "Execution time: " << duration.count() << " microseconds." << endl;


//    printArray(testing_array,length);

    return 0;
}
