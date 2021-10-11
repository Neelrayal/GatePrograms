#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "How many numbers you want to compare? \n"; 
    cin >> n;
    int maxx = INT_MIN, minn = INT_MAX, len, t1, t2; 
    if ( n & 1){ // no2
        cin >> t1; 
        maxx = minn = t1 ;
        len = n/2;
    }
    else{
        cin >> t1 >> t2; 
        if( t1 > t2){
            maxx = t1; 
            minn = t2; 
        } 
        else{
            maxx = t2; 
            minn = t1; 
        }
        len = n/2-1; 
    }    
    for(int i=1; i<=len; ++i){
        cin >> t1 >> t2; 
        if ( t1 > t2){
            if( t1 > maxx) maxx = t1; 
            if(t2 < minn ) minn = t2; 
        }
        else{
            if( t2 > maxx) maxx = t2; 
            if(t1 < minn) minn = t1; 
        }        
    }
    cout << "Max: " << maxx << " Min: " << minn << "\n";
}