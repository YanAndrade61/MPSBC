#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, a, b, teste = 1;
    string nomes[2];

    while(true){

        cin >> N;
        if(N == 0)break;

        cin >> nomes[0] >> nomes[1];

        cout << "Teste " << teste << "\n";
        for (int i = 0; i < N; i++){
            cin >> a >> b;
            cout << nomes[(a+b)% 2] << "\n";    
        }
        cout << endl;

        teste++;
    }
    
    return 0;
}