#include <bits/stdc++.h>

using namespace std;

int main(){

    int Q,D,P,dias,pag;
    while(true){
        
        cin >> Q >> D >> P;
        if(!cin)break;
        
        // dias = (D*P)/(P-Q);
        pag = (int)abs((Q*D*P)/(P-Q));
        
        cout << pag;
        if(pag > 1)
            cout << " paginas\n";
        else
            cout << " pagina\n";
    }

    return 0;
}