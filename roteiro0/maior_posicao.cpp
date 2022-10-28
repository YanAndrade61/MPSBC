#include <bits/stdc++.h>

using namespace std;

int main(){

    int maior = 0, n, posicao;
    
    for(int i = 0; i < 100; i++){

        cin >> n;
        if(n > maior){
            maior = n;
            posicao = i+1;
        }
    }
    cout << maior << "\n";
    cout << posicao << "\n";
    
    return 0;
}