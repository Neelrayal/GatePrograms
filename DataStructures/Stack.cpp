#include <bits/stdc++.h>
using namespace std;

const int MAXX = 100; // declaring the size of stack 
int top = -1;
int Stack[MAXX]; // stack is an STL in c++. 

void push(int x){
    if(top == MAXX-1){
        cout << "Overfow\n"; 
    }
    else{
        top += 1; 
        Stack[top] = x; 
    }
}

void pop(){
    if (top == -1){
        cout << "Underflow\n"; 
    }
    else{
        cout << "Popped element: " << Stack[top] << "\n";
        top -= 1; 
    }
}

/* Linked List implementation of Stack */ 

struct node{ 
    int data; 
    node* next; 
};
node* head = NULL; 

void LLstackPush(int item){
    node* temp = ( struct node* )malloc( sizeof(node) ); 
    if (temp == NULL){ 
        cout << "Overflow, memory not available\n"; 
    }
    else{
        temp->data = item; 
        temp->next = head; 
        head = temp; 
    }
}

void LLstackPop(){
    node* temp = head; 
    temp = head; 
    head = head->next; 
    cout << "Popped element: " << temp->data << "\n"; 
    free(temp); 
}

void Display(){
    node* temp = head; 
    while(temp){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << "\n";
}

int main(){
    push(1); 
    push(2); 
    push(3); 
    pop(); 
    pop(); 
    pop(); 
    pop(); 

    LLstackPush(1); 
    LLstackPush(2);
    LLstackPush(3);
    LLstackPush(4);
    LLstackPush(5);
    Display(); 

    LLstackPop(); 
    LLstackPop(); 
    Display();
}