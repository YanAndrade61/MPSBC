#include <bits/stdc++.h>

using namespace std;


int main(){

    int a,b,teste=1,N,dif;

    while (true){

        cin >> N;
        if(N == 0)break;

        dif=0;
        cout << "Teste " << teste++ << endl;
        for (int i = 0; i < N; i++){
            cin >> a >> b;
            dif = a-b + dif;
            cout << dif << endl;
        }
        cout << endl;
    }
    
    return 0;
}