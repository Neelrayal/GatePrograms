#include <bits/stdc++.h>
using namespace std;

struct node{
    int data; 
    node* next;
};
node* head = NULL;



void Display(){
    node* temp = head; 
    while(temp){
        cout << temp->data << " ";  
        temp = temp->next; 
    }
    cout << "\n";
}



node* Create(int data){
    struct node* newNode = (struct node* ) malloc( sizeof( struct node ) );
    newNode->data = data; 
    newNode->next = NULL;    
    return newNode; 
}

void atEnd(int data){    
    //struct node* newNode = (struct node* ) malloc( sizeof( struct node ) );
    node* newNode = Create(data);     
    
    if( head == NULL){
        head = newNode;
    }
    else{
        node* t = head; 
        while(t->next){
            t = t->next; 
        }
        t->next = newNode; 
    }
    Display();
}

void atFront(int data){    
    node* newNode = Create(data);
    //cout <<" temp->data: " << newNode->data << "\n";
    if( head == NULL){
        // this means head is the front. 
        head = newNode; 
    }
    else{
        node* temp = head; 
        //cout <<"  NOT NULL;        
        newNode->next = head;
        //cout << "newNode next: " << newNode->next << "\n";
        head = newNode;  
        //cout <<" head->next: "  << head->next << "\n";
    }
    Display();
}

void DeleteFromFront(){
    node* temp = head; 
    head = head->next;
    cout << "After deleting from front:\n";
    Display(); 
    free(temp);
}

void DeleteFromEnd(){
    node* temp = head; 
    while(temp->next->next)
        temp = temp->next; 
    free(temp->next);         
    temp->next = NULL; 
    cout << "After deleting from end:\n";
    Display(); 
}


void DeleteElement(int data1){
    node* temp = head; 
    node* pre = head; 
    bool flag = false; 
    while(temp){
        if(temp->data == data1){
            pre->next = temp->next; 
            flag = true;             
            free(temp); 
            cout << "After deleting element:\n";
            Display(); 
            break; 
        }
        else{
            pre = temp; 
            temp = temp->next; 
        }
        
    }
    if(!flag)
        cout << "Element not present in the linked list\n";
}

void reverseSSLIterative(){
    cout << "Original:"; 
    Display();     

    node* temp = NULL, *prev = NULL, *current = head;      
    while(current){
        temp = current->next; 
        current->next = prev; 
        prev = current; 
        current = temp; 
    }
    head = prev;
    cout << "Reversed: ";
    Display();
}

void reverseSSLRecursive(struct node* prev,struct node *current){    
    // Now working properly
    cout << "current is: " << current->data << "\n";
    if(current != NULL && current->next != NULL){
        //cout << "old current: " << current->next->data << "\n"; 
        reverseSSLRecursive(current, current->next); 
        current->next = prev;                   
    }
    else{
        cout << "head is: " << head->data << "\n";
        head = prev;         
        //cout << "head is: " << head->data << "\n";
    }    
}


int main(){     
    head = NULL;
    atEnd(1);    
    atEnd(2);
    atEnd(3);
    atEnd(4); 
    atFront(5);
    atFront(6);    
    //DeleteFromFront();
    //DeleteFromEnd();
    //DeleteElement(2); 
    cout << "Before SSL: ";
    Display();     
    //reverseSSLRecursive(NULL, head); 
}


