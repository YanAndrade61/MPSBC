#include <bits/stdc++.h>

using namespace std;

int main(){

    int max, a, b;
    char op;

    cin >> max >> a >> op >> b;
    
    a = op == '+' ? a+b : a*b;
    a > max ? cout << "OVERFLOW\n" : cout << "OK\n";
    
    return 0;
}