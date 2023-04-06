#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// Stack data structure implementation via linked list
class Node{
public:
    int data; // content of the node
    Node *next; // Pointer to the next node
};



class Stack{
public:
    Node *top; // Pointer to the top
    Stack(){
        top = nullptr;
    }


    // Function to display the stack elements
    void display(){
        if (isEmpty()){
            cout << "Error : Stack is empty! \n";
            return;
        }
        Node *curr = top;
        cout<<"[";
        while (curr != NULL){
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << "NULL ]\n";
    }


    int stackTop(){
        if (!isEmpty()){
            return top->data;
        }
    }


    bool isEmpty(){
        return top == nullptr;
    }

    // Since this is a stack implemented using a linked list, this will always be false. But for the sake of completeness, included the full logic.
    bool isFull(){
        Node *new_node = new Node();
        if (new_node == nullptr)
            return true;  //This line will not be executed anytime.

        else{
            delete new_node;
            return false;
        }
    }


    void push(int data_to_add){
        if (!isFull()){
            Node *new_node = new Node;
            new_node->data = data_to_add;
            new_node->next = top;
            top = new_node;
        }
        else{
            cout << "Error : Stack Overflow! \n";  //This line will not be executed anytime.
        }
    }


    void pop(){
        if (!isEmpty()){
            Node *tempory = top;
            top = tempory->next;
            delete tempory;
        }
    }

};



int main() {
    srand(time(NULL));
    int arr[14];
    for (int i = 0; i <= 14; i++) {
        arr[i] = rand() % 100;
    }
    Stack sample_stack;
    auto start = std::chrono::high_resolution_clock::now();
    sample_stack.push(arr[0]);
    sample_stack.push(arr[1]);
    sample_stack.push(arr[2]);
    sample_stack.push(arr[3]);
    sample_stack.push(arr[4]);
    sample_stack.push(arr[5]);
    sample_stack.push(arr[6]);
    sample_stack.push(arr[7]);
    sample_stack.push(arr[8]);
    sample_stack.push(arr[9]);
    sample_stack.display();
    sample_stack.pop();
    sample_stack.pop();
    sample_stack.pop();
    sample_stack.pop();
    sample_stack.pop();
    sample_stack.display();
    sample_stack.push(arr[10]);
    sample_stack.push(arr[11]);
    sample_stack.push(arr[12]);
    sample_stack.push(arr[13]);
    sample_stack.display();
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<std::chrono::microseconds>(stop - start);  // Calculate the duration
    cout << "Execution time: " << duration.count() << " microseconds." << endl;


    return 0;
}
