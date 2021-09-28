#include<bits/stdc++.h>
using namespace std;

struct node{
    int data; 
    node* left, *right; 
};
node* head = NULL;

/* Delcarations, to get rid of rearranging functions */
void insertBSTLL(int item);  // LL for linked list
node* createNode(int data); 
void inorderTraversal(node* t); 
void inorder(node* t);
void postorder(node* t); 
void search(node* root, int key); 
void findMIN(); 
void findMAX();
void Delete(node* , int);

node* createNode(int data){
    node* temp = (node*)malloc(sizeof(node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
}

void insertBSTLL(node* root, int item){        
    if ( head == NULL){
        head = createNode(item); 
        return ;
    }
    if( item <= root->data){
        //cout << "left\n";
        /*
        The reason for this pre-checking is; if the root->left is NULL
        then we will try to access data from a NULL - which is invalid. 
        So before reaching NULL, we are assigned the new node to it.
        */

        /* 
        A better way to do this is below insert()
        taken from wiki.
        */ 

        if( root->left == NULL ){
            root->left = createNode(item);                 
        }        
        else{
            insertBSTLL(root->left, item);
        }            
    }
    else{
        //cout << "right\n";
        if( root->right == NULL){
            root->right = createNode(item);
        }
        else{
            insertBSTLL(root->right, item);    
        }                
    }
        
}

/* Traversal Techniques: 
    1. Inorder      L root R 
    2. Preorder     root L R
    3. Post Order   L R root
*/

void inorderTraversal(node* t){    
    if(t == NULL)
        return;
    inorderTraversal(t->left); 
    cout << t->data << " ";
    inorderTraversal(t->right);
}

void preorder(node *t){
    if ( t == NULL ) return ;
    cout << t->data << " ";
    preorder(t->left);
    preorder(t->right);
}

void postorder(node* t){
    if( t == NULL ) return;
    postorder(t->left);
    postorder(t->right);
    cout << t->data << " ";
}

void search(node* root, int key){
    if( root == NULL ){
        cout << "key not found\n";
        return; 
    }        
    if ( key == root->data){
        cout << "key found in BST\n";        
    }
    else if(key < root->data){
        search(root->left, key);
    }
    else{
        search(root->right, key); 
    }
}

void findMIN(){
    node* t = head; 
    while(t->left)
        t = t->left; 
    cout << "Min in BST: " << t->data << "\n";
}

void findMAX(){
    node* t = head; 
    while(t->right)
        t = t->right; 
    cout << "MAX in BST: " << t->data << "\n";
}


void insert(node* &root, int item){
    if(!root){
        root = createNode(item);        
    }
    else if(item <= root->data )
        insert(root->left, item);
    else
        insert(root->right, item);

}
bool  vis[100]; 
bool find_node(node* t, int key){
    if(t == NULL && t->data == key)
        return true; 
    else 
        return false; 
    if( t->data <= key){
        find_node(t->right, key);
    }
    else
        find_node(t->left, key);
}

/* Not working, will do later */ 
void Delete(node *t,node *pre, int key){
    if ( t == NULL)
        return ; 
    if( t->data < key){
        Delete(t->right,t, key);
    }
    else if(t->data > key)
        Delete(t->left,t, key);
    else{
        if( t->left == NULL && t->right == NULL){

        }
            
    }
    
}

int main(){
    int toInsert[] = {16, 24, 18, 28, 26, 30, 8, 6, 12, 4, 6, 14};    
    int len = sizeof(toInsert)/sizeof(toInsert[0]);        
    for(int i=0; i<len; ++i){
        insert( head, toInsert[i] );
    }
    Delete(head, 16); 
}