#include <bits/stdc++.h>

using namespace std;

int main(){

    int A,B,C;
    while(true){
        
        cin >> A >> B >> C;
        if(!cin)break;
        if(A == B && A == C){
           cout << "*\n";
        } 
        else if(A==B){
            cout << "C\n";
        }
        else if(A==C){
            cout << "B\n";
        }
        else if(B==C){
            cout << "A\n";
        }
        
    }
    
    
    return 0;
}
