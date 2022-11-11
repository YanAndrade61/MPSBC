#include <bits/stdc++.h>

using namespace std;

int main(){

    int A,D,imp;
    while(true){
        cin >> A >> D;
        if(A == 0 && D == 0)break;
        
        int at[A],def[D];
        imp = 0;
        for (int i = 0; i < A; i++)
            cin >> at[i];
        for (int i = 0; i < D; i++)
            cin >> def[i];
        
        sort(at,at+A);
        sort(def,def+D);
        for (int i = 0; i < A; i++){
            if(at[i] < def[1]){
               imp = 1;
               break; 
            }
        }
        imp ? cout << "Y\n" : cout << "N\n";
        
    }

    return 0;
}