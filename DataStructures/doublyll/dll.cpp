#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* Head;

void InsertAtHead(int x){
Node* newNode = new Node();
    newNode->data= x;
    newNode->next= Head;
   if(Head != nullptr) Head->prev = newNode;
    Head = newNode;
    newNode->prev = nullptr;
}

void Print(){
    Node* temp =Head;
    while(temp != nullptr){
        cout<<"|"<<temp->data<<"|"<<"<->";
        temp = temp->next;
    }
    cout<<" End"<<endl;
}

void InsertAtEnd(int x){
    Node* newNode = new Node();
    newNode->data =x;
    newNode->next = nullptr;
    Node* temp = Head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev= temp;
}
void ReversePrint(){
    Node* temp = Head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    cout<<"Reversing\n";
    while(temp != nullptr){
    cout<<temp->data<<"<=>";
    temp = temp->prev;
    }

}
void InsertAtNth(int x, int position){
    Node* newNode = new Node();
    newNode->data = x;
    Node* temp = Head;
    Node* temp2 = Head->next;
    for(int i = 1; i<position-1;i++){
        temp = temp->next;
        temp2 = temp2->next;
    }
    newNode->next = temp2;
    temp->next = newNode;
    newNode->prev = temp;
    temp2->prev = newNode;
}

void DeleteAtNth(int position){
    Node* temp = Head;
    Node* temp1 = Head->next;
    for(int i =1; i<position-1;i++){
    temp = temp->next;
        temp1 = temp1->next;
    }
    Node*toDelete = temp1;
    temp->next = temp1->next;
    temp1 = temp1->next;
    temp1->prev = temp;
    cout<<"Deleted"<<endl;
    delete toDelete;
}
void ReverseDll(){
    Node* nextToCurrent = nullptr;
    Node* current = Head;
    Node* previousToCurrent = nullptr;

    while(current != nullptr){
    previousToCurrent = current->next;
    current->next = nextToCurrent;
    current->prev = previousToCurrent;
    nextToCurrent = current;
    current = previousToCurrent;
    }
    Head = nextToCurrent;
}

void Reverse_using_recursion(Node*current,Node*previous,Node*next){
    if(current == nullptr) return;
    Reverse_using_recursion(current,current->prev,current->next);
    if(current->next == nullptr) Head = current;
    current->next = previous;
    current->prev = next;
    return;
}

int main(){
    InsertAtHead(10);
    InsertAtHead(9);
    InsertAtHead(8);
    Print();
    InsertAtEnd(12);
    InsertAtNth(11,4);
    Print(); 
    ReversePrint();
    Print();
    ReverseDll();
    Print();
    DeleteAtNth(4);
    Print();
    Reverse_using_recursion(Head,Head->prev,Head->next);
    Print();
}
