#include <bits/stdc++.h>

using namespace std;


int main(){

    int S,E,N,cap,atual=0,pass = 0;

    cin >> N >> cap;
        
    for (int i = 0; i < N; i++){
        cin >> S >> E;
        atual += E - S;
        if(atual > cap){
            pass = 1;
        }    
    }
    if(pass == 1)
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
    
    return 0;
}