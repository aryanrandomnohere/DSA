

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

// Stack using linked list
Node* listTop = nullptr;

// Stack using array
int arrayTop = -1;
const int size = 50;
int arr[size];

// ---------- ARRAY STACK FUNCTIONS ----------

void pushArray(int value) {
    if (arrayTop == size - 1) {
        cout << "Array Stack Overflow!\n";
        return; 
    }
    arr[++arrayTop] = value;
    cout << "Pushed " << value << " to array stack.\n";
}

void popArray() {
    if (arrayTop == -1) {
        cout << "Array Stack Underflow!\n";
        return;
    }
    cout << "Popped " << arr[arrayTop--] << " from array stack.\n";
}

void arrayIsEmpty() {
    if (arrayTop == -1)
        cout << "Array stack is empty.\n";
    else
        cout << "Array stack is not empty.\n";
}

void arrayIsFull() {
    if (arrayTop == size - 1)
        cout << "Array stack is full.\n";
    else
        cout << "Array stack is not full.\n";
}

// ---------- LINKED LIST STACK FUNCTIONS ----------

void pushList(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->link = listTop;
    listTop = temp;
    cout << "Pushed " << value << " to list stack.\n";
}

void popList() {
    if (listTop == nullptr) {
        cout << "List Stack Underflow!\n";
        return;
    }
    cout << "Popped " << listTop->data << " from list stack.\n";
    Node* temp = listTop;
    listTop = listTop->link;
    delete temp;
}

void listIsEmpty() {
    if (listTop == nullptr)
        cout << "List stack is empty.\n";
    else
        cout << "List stack is not empty.\n";
}

// ---------- MAIN FUNCTION ----------

int main() {
    // Testing Array Stack
    pushArray(10);
    pushArray(20);
    arrayIsEmpty();
    arrayIsFull();
    popArray();
    popArray();
    popArray();

    cout << "\n";

    // Testing Linked List Stack
    pushList(100);
    pushList(200);
    listIsEmpty();
    popList();
    popList();
    popList();

    return 0;
}
