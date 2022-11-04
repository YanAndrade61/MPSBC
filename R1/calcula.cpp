#include <bits/stdc++.h>

using namespace std;


int main(){

    int res,a,teste=1,m;
    char op;

    while (true){

        cin >> m;
        if(m == 0)break;

        cin >> res;
        
        for (int i = 0; i < m-1; i++){
            cin >> op >> a;
            res = op == '+' ? res+a : res-a; 
        }

        cout << "Teste " << teste++ << endl;
        cout << res << endl << endl;

    }
    
    return 0;
}