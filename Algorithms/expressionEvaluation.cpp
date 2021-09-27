#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
        return true; 
    else 
        return false; 
}

int precedence(char ch){

    if (ch == '^')
        return 3; 
    else if (ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1; 
    else{
        //cout << "ch is: " << ch << " ";
        //cout << "exception\n";
        return 0;
    }        
}
void InfixToPostfix(string str){
    stack<char> st; 
    for(int i=0; i<str.length(); ++i){
        if( str[i] == '('){
            st.push('('); 
        }
        else if( isOperator( str[i] ) ){ // if current char is an operator            
            while(!st.empty()  && precedence(st.top()) >=  precedence(str[i]) ){
                //cout << "here\n";
                char temp = st.top();
                //cout << "TOS is: " << temp << " done\n";                
                cout << st.top();
                st.pop(); 
            }
            //cout << "pushing: " << str[i] << "\n";
            st.push(str[i]);             
        }
        else if( str[i] == ')' ){
            while(st.top() != '('){
                cout << st.top(); 
                st.pop();
            }
            st.pop();
        }
        else{ // current operator is an operand
            cout << str[i]; 
        }
    }
    while(!st.empty()){
        cout << st.top(); 
        st.pop(); 
    }
    cout << "\n";
}

void PostfixEval(string str){
    stack<int> st;  
    int op1, op2;    
    for(int i=0; i<str.length(); ++i){        
        if( !(isOperator(str[i])) ){ // means if the char is not an operator
            int temp = str[i] - '0';
            st.push(temp);
        }
        else{
            op2 = st.top(); 
            st.pop();
            op1 = st.top();                
            st.pop();
            if( str[i] == '*' ){                
                st.push(op1*op2);
            }       
            else if( str[i] == '-'){
                st.push(op1 - op2);
            }
            else if( str[i] == '+'){
                st.push(op1 + op2);
            }
            else if( str[i] == '/'){
                st.push(op1/op2);
            }
            else if(str[i] == '^'){
                st.push( pow(op1,op2) );
            }
            else{
                cout << "exception\n";
            }
        }
    }
    cout << str << " evals to : " << st.top();
    st.pop();
}

int main(){
    string infix = "a+b*(c^d-e)^(f+g*h)-i"; 
    string a = "a+b*(c+d)/f+d*e";
    InfixToPostfix(a); 

    string postfix = "231*+9-"; 
    /*
    Will update in future. There is no delimeter to differentie 1-digit with n-digit no. 
    Here 10 is treated as 1 and 0 separately. 
    */
    PostfixEval(postfix);
}