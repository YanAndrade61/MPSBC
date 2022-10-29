#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, teste=1;
    while (true){
        
        cin >> N;
        if(N == 0)break;
        
        cout << "Teste " << teste << "\n"; 
        cout << (int)(pow(2,N)-1) << "\n\n";
        
        teste++;   
    }
    return 0;
}