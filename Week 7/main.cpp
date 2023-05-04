#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
// Finds and returns the minimum key(int type) value inside the provided tree.  (THIS FUNCTION IS EXPLICITLY IMPLEMENTED) 
int minFinder(struct node* root){
    if (root -> left == nullptr && root -> right == nullptr)
        return root -> key;
    else if (root -> left == nullptr) // Has a right child but no left child.
        return minFinder(root -> right);
    else if (root -> right == nullptr) //Has a left child but no right child.
        return minFinder(root -> left);
    else{ //Has both children. But note that since this is a binary tree, going left is enough since the right side elements is already greater. Actually no need to add the last else if clause here, added for easy readability/understandability.
        return minFinder(root -> left);
    }
}

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == nullptr)
        return;
    else{
    traverseInOrder(root -> left);
    cout<<root -> key << " ";
    traverseInOrder(root -> right);
    }
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr){ // base case
        node = new struct node;
        node -> key = key;
        node -> right = nullptr;
        node -> left = nullptr;
    }
    else if (node -> key <= key) //Duplicate keys will be added to the left side.
         node -> right = insertNode( node -> right,key);
    else if (node -> key > key)
         node -> left= insertNode(node -> left,key);
    return node;



}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) // base case
        return root;
    else if (root -> key < key)
        root -> right = deleteNode(root -> right , key);
    else if (root -> key > key)
        root -> left = deleteNode(root -> left, key);
    else{ //case where the given key is in the root.
        if (root -> left == nullptr && root -> right == nullptr){   // case of having no children
            delete root;
            root = nullptr;
        }
        else if (root -> left == nullptr){ //case of no left child but do have a right child
            struct node *temp = root;
            root = root -> right ;
            delete temp;
        }
        else if (root -> right == nullptr){ // case of no right child but do have a left child
            node *temp = root;
            root = root -> left ;
            delete temp;
        }
        else { // case of having both children. chose to go with minimum of the right sub tree.
            root -> key = minFinder(root -> right);
            root -> right = deleteNode(root -> right, root -> key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
