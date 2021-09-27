#include<bits/stdc++.h>
using namespace std;

int Queue[4];
int front = -1, rear = -1;
int n = 4; //size of queue

void enqueue(int data){
    if( front == (rear+1)%n ){ // queue is full        
        cout << front << " " << rear << " ";
        cout << "Queue is full\n"; 
    }
    else{        
        if( front == -1 && rear == -1){
            //first time enqueing. 
            // Will set front = 0 for correct working            
            front = 0; 
        }        
        cout << data << "  enqueued\n";
        rear = (rear+1)%n;
        Queue[ rear ]  = data;                 
    }
}

void dequeue(){

    //cout << "front: " << front << " rear: " << rear << " ";    
    if ( front == -1 ){
        cout << "underflow\n"; 
    }    
    else if (front == rear){ // This step is IMP
        cout << "dequeued element: " << Queue[front] << "\n";         
        front = -1; 
        rear = -1; 

    }
    else{
        cout << "dequeued element: " << Queue[front] << "\n"; 
        front = (front + 1)%n; 
    }
}
int main(){
    dequeue(); 
    enqueue(1); 
    enqueue(2);
    enqueue(3);
    enqueue(4); 
    enqueue(5);

    dequeue(); 
    dequeue(); 
    dequeue(); 
    dequeue(); 
    dequeue(); 

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(41);
    dequeue();
    dequeue();
    enqueue(5);
    enqueue(6);
    enqueue(7);
}