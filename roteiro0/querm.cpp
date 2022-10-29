#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, p,teste=1;

    while (true){
        
        cin >> N;
        if(N == 0)break;
        
        cout << "Teste " << teste << "\n"; 
        for (int i = 0; i < N; i++){
            cin >> p;
            if(p == i+1){
                cout << p << "\n";
            }
        }
        teste++;   
    }
    return 0;
}