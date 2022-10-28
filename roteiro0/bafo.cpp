#include <bits/stdc++.h>

using namespace std;

int main(){

    int R, aldo, beto, a, b, teste=1;

    while(true){

        cin >> R;
        if(R == 0)break;

        aldo = 0;
        beto = 0;
        for (int i = 0; i < R; i++){
            cin >> a >> b;
            aldo += a;
            beto += b;
        }
        
        cout << "Teste " << teste << "\n";
        if(aldo > beto)
            cout << "Aldo" << "\n\n";
        else
            cout << "Beto" << "\n\n";
        
        teste++;
    }
    return 0;
}