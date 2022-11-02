#include <bits/stdc++.h>

using namespace std;

int main(){

    int V, conta = 7;
    vector<int> taxas(3,0);
    cin >> V;
    
    taxas[0] = V > 30 ? 20 : (V > 10 ? V-10 : 0);
    taxas[1] = V > 100 ? 70 : (V > 30 ? V-30 : 0);
    taxas[2] = V > 100 ? V-100 : 0;
    conta += taxas[0] + taxas[1]*2 + taxas[2]*5;
    cout << conta << "\n";

    return 0;
}