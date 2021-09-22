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

int main(){     
    head = NULL;
    atEnd(1);    
    atEnd(2);
    atEnd(3);
    atEnd(4); 
    atFront(5);
    atFront(6);         
    
}


