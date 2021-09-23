#include<bits/stdc++.h>
using namespace std;

struct node{
    int data; 
    int priority; 
    node* next; 
}; 
node* head = NULL, *last = NULL; 

void insert(int item, int prio){
    node* temp = (node*)malloc(sizeof(node)); 
    temp->data = item; 
    temp->priority = prio;
    if(head == NULL){
        head = temp;
        last = temp; 
    }        
    else{
        last->next = temp; 
        last = temp; 
    }
}

void getHighestPriority(){
    node* temp = head; 
    int prio = INT_MAX, value; 
    while(temp){
        if ( temp->priority < prio){
            prio = temp->priority; 
            value = temp->data; 
        }
        temp = temp->next;
    }
    cout << "Highest Priority:" << prio << " It's value: " << value << "\n";
}

void deleteHighestPriority(){
    node* temp = head; 
    
}

void Display(){
    node* temp = head; 
    cout << "Priority\tvalue\n" ;
    while(temp){
        cout << temp->priority << "\t\t" << temp->data << "\n";
        temp = temp->next; 
    }
}


int main(){
    insert(1,0);
    insert(2,1); 
    insert(3,0);
    Display();

    getHighestPriority();

}