#include <bits/stdc++.h>

using namespace std;

int main(){

    int c,v,N,qtd;

    while (true){

        cin >> N;
        if(N == 0)break;
        
        qtd = 0;
        for (int i = 0; i < N; i++){
            cin >> c >> v;
            qtd += v/2;    
        }
        cout << qtd/2 << endl;
    }
    
    return 0;
}