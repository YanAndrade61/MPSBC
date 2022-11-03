#include <bits/stdc++.h>

using namespace std;

int main(){

    int V,notas[] = {100,50,20,10,5,2,1};
    cin >> V;
    
    cout << V << "\n";
    for (int i = 0; i < 7; i++){
        cout << V/notas[i] << " nota(s) de R$ " << notas[i] << ",00\n";
        V = V % notas[i];
    }

    return 0;
}