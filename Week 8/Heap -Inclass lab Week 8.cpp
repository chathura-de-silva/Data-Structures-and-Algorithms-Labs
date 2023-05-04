#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root){
    int largest=root;
    int left = 2*root+1;
    int right = 2*root+2;

    if (left < n and arr[largest]<arr[left])
        largest = left;
    if (right<n and arr[largest]<arr[right])
        largest=right;

    if (largest != root){
        swap(arr[root],arr[largest]);
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n){
    // First Builds the Max-Heap.
    for (int i = (n-1)/2 ; i>=0; i--)
        heapify(arr,n, i);
// Then does the sorting process
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0); // when calling heapify, array size being reduced by 1 in each iteration via i.
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main(){
    int n=0;
    cout<< "Enter the array size :"<<endl;
    cin>>n;

    int heap_arr[n];
    cout<<"Enter the array as "<< n << " space separated integers :"<<endl;
    for (int i=0 ;i<n; i++)
        cin>>heap_arr[i];



    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
