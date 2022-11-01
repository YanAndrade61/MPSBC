#include <bits/stdc++.h>

using namespace std;

int main(){

    int max, a, b;
    char op;

    cin >> max >> a >> op >> b;
    
    if(op == '+')
        a += b;
    else
        a *= b;
    
    if(a > max)
        cout << "OVERFLOW\n";
    else
        cout << "OK\n";

    return 0;
}