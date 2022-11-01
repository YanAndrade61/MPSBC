#include <bits/stdc++.h>

using namespace std;

int main(){

    int Q,D,P,dias,pag;
    while(true){
        
        cin >> Q >> D >> P;
        if(!cin)break;
        
        pag = (int)abs((Q*D*P)/(P-Q));
        
        cout << pag;
        pag > 1 ? cout << " paginas\n" : cout << " pagina\n";
    
    }

    return 0;
}