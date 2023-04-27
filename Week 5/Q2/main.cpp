#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void generateRandomArray(vector<int>&array, int n) {
    srand(time(NULL));  // Initialize random number generator
    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 100);  // Generate a random integer between 0 and 99
    }
}

void printArray(vector<int>&arr, int n) {
    cout<<"[";
    for (int i = 0; i < n; i++) {
        cout << arr[i] ;
        if (i!= n-1)
            cout<<",";
    }
    cout<<"]";
}

void insertion(vector<int>& arr, int element, int n) {
    int pointer = n;
    for (int i = 0; i < n; i++) {
        if (element < arr[i]) {
            pointer = i;
            break;
        }
    }
    arr.resize(n+ 1);
    for (int j = n; j > pointer; j--) {
        arr[j] = arr[j - 1];
    }

    arr[pointer] = element;
}

double median(vector<int>&arr,int i){
    int mid = i/2;
    if (i==0 or mid/2!=0)
        return arr[mid];
    else
        return (arr[mid]+arr[mid+1])/2.0;
}

string spaceStr(int k){
    string spaceString=" ";
    for (int i=0;i<k;i++)
        spaceString+=" ";
    return spaceString;
}

int main() {
    int n = 0;
    vector<int> in_arr, out_arr;

    cout << "Enter the array length : ";
    cin >> n;

    generateRandomArray(in_arr, n);

    cout<<"The generated array is : ";
    printArray(in_arr,n);
    cout<<endl;

    cout<<"Sorted"<<spaceStr(3*n+2) << "Median"<<endl;

    for (int i = 0; i < n; i++) {
        insertion(out_arr, in_arr[i],i);
        printArray(out_arr,i+1);
        std::cout<<spaceStr(3*n+2-3*i)<< std::fixed << std::setprecision(1) << median(out_arr,i) << std::endl;
    }
    return 0;
}