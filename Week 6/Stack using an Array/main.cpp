#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

struct Stack {
    vector<int> arr;
    int pointer = -1;
    int length;
    Stack(int len) : arr(len),length(len) {}

    void display(){
        if (pointer==-1){
            cout<<"Error : Array is Empty"<<endl;
            return;
        }
        cout<<"[";
        for (int i=0 ; i <= pointer;i++){
            cout<<arr[i];
            if (i!=pointer)
                cout<<",";
            else
                cout<<"]"<<endl;

        }
    }


    int stackTop(){
        if (pointer==-1) {
            cout<<"Error : Stack is empty!"<<endl;
            return 0;
        }
        return arr[pointer];
    }

    bool isEmpty(){
        if (pointer ==-1)
            return true;
        return false;
    }

    bool isFull(){
        if (pointer==length-1)
            return true;
        return false;
    }


    void push(int element){
        if (pointer == length-1){
            cout<<"Error : Stack overflow!"<<endl;
            return;
        }
        pointer++;
        arr[pointer]=element;
    }

    int pop() {
        if (pointer == -1) {
            throw runtime_error("Error : Stack underflow");
        }
        pointer--;
        return arr[pointer+1];
    }
};

int main() {
    srand(time(NULL));
    int arr[14];
    for (int i=0 ; i<=14;i++){
        arr[i]=rand() % 100;
    }
    Stack * sample_stack = new Stack(14);
    auto start = std::chrono::high_resolution_clock::now();
    sample_stack->push(arr[0]);
    sample_stack->push(arr[1]);
    sample_stack->push(arr[2]);
    sample_stack->push(arr[3]);
    sample_stack->push(arr[4]);
    sample_stack->push(arr[5]);
    sample_stack->push(arr[6]);
    sample_stack->push(arr[7]);
    sample_stack->push(arr[8]);
    sample_stack->push(arr[9]);
    sample_stack -> display();
    sample_stack->pop();
    sample_stack->pop();
    sample_stack->pop();
    sample_stack->pop();
    sample_stack->pop();
    sample_stack -> display();
    sample_stack->push(arr[10]);
    sample_stack->push(arr[11]);
    sample_stack->push(arr[12]);
    sample_stack->push(arr[13]);
    sample_stack -> display();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::microseconds>(stop - start);  // Calculate the duration
    cout << "Execution time: " << duration.count() << " microseconds." << endl;




    return 0;
}
