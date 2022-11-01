#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,fatorial = 1;
    cin >> N;
    for (int i = N; i > 0; i--)
        fatorial *= i;
    
    cout << fatorial << "\n";

    return 0;
}