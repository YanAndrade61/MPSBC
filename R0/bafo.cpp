#include <bits/stdc++.h>

using namespace std;

int main(){

    int R, aldo, beto, a, b, teste=1;

    while(true){

        cin >> R;
        if(R == 0)break;

        aldo = beto = 0;
        for (int i = 0; i < R; i++){
            cin >> a >> b;
            aldo += a;
            beto += b;
        }
        
        cout << "Teste " << teste++ << "\n";
        cout << (aldo > beto ? "Aldo\n\n" : "Beto\n\n");
    }
    return 0;
}