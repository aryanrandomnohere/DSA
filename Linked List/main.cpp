#include <iostream>
using namespace std;
struct node {
    int data;
    node* link;
};
node* Head = nullptr;


void print_node(){
    node* temp = Head;
    while(temp->link != nullptr){
    cout<<temp->data;
    cout<<"->"; 
    temp = temp->link;
    }
    cout<<temp->data<<"->";
    cout<<"end"<<endl;
    return;
}
void add_at_beginning(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->link = Head;
    Head = newNode;   
}


void insert_at_end(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->link = nullptr;
    if(Head == nullptr){
        Head = newNode;
        cout<<"Added the first node";
        return;
    }
    node* i = Head;
    while(i->link != nullptr){
    i=i->link;
      }
    i->link = newNode;
}

void insert_at_position(int position,int value){
    node* temp = Head;
    if(position == 1){
        cout<<"Adding at the beginning"<<endl;
        add_at_beginning(value);
        return;
    }
    for(int i =1; i<position-1; i++){
        if(temp == nullptr) {
            cout<<"Cannot Add the value at this position the list is small adding at the end"<<endl;
            insert_at_end(value);
            return;
        }
        temp = temp->link;
    }
    node* newNode = new node();
    newNode->link = temp->link;
    newNode->data = value;
    temp->link = newNode;
    return;
}


void delete_at_position(int position){
    node* temp = Head;
    for(int i =1; i < position - 1; i++){
        if(temp == nullptr){
            cout<<"The value to be deleted is out of bounds"<<endl;
            return;
        }
        temp = temp->link;
    }
    node* toDelete = temp->link;
    cout<<"Deleting : "<<toDelete->data<<" at position : "<<position<<endl;
    temp->link = toDelete->link;
    delete toDelete;
    return;
}

void reverse_linkedlist(){
   node* current = Head;
    node* pointsto = nullptr;
    node* nextNode;
    cout<<"Reversing"<<endl;
    while(current != nullptr){
        nextNode = current->link;
        current->link= pointsto;
        pointsto= current;
        current = nextNode;
    }
    Head = pointsto;
    return;
}

void reverse_using_recursion(node* current,node* previousPointer){
  if(current->link == nullptr){
        Head =current;
        current->link = previousPointer;
    return;
    }
    reverse_using_recursion(current->link,current);
    current->link = previousPointer;
    return;
}

void print_using_recursion(node* current){
    if(current == nullptr) return;
    print_using_recursion(current->link);
    cout<<current->data<<"->";
}

int main() {
    add_at_beginning(13);
    add_at_beginning(12);
    print_node();
    insert_at_end(14);
    print_node();
    add_at_beginning(10);
    print_node();
    insert_at_position(2,11);
    print_node();
    insert_at_position(11,29);
    print_node();
    insert_at_position(1,9);
    print_node();
    delete_at_position(2);
    print_node();
    reverse_linkedlist();
    print_node();
    cout<<Head->data<<endl;
    cout<<"Printing Reverse usng recursion"<<endl;
    print_using_recursion(Head);
    cout<<"Reversing the list using recursion"<<endl;
    reverse_using_recursion(Head,nullptr);
    print_node();
    return 0;
}
