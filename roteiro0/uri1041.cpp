#include <bits/stdc++.h>

using namespace std;

int main(){

    float x,y;
    cin >> x >> y;
    
    if( x == 0 && y == 0)
        cout << "origem\n";
    else if( x == 0)
        cout << "Eixo X\n";
    else if( y == 0)
        cout << "Eixo Y\n";

    if( x > 0 && y > 0)
        cout << "Q1\n";
    if( x < 0 && y > 0)
        cout << "Q2\n";
    if( x < 0 && y < 0)
        cout << "Q3\n";
    if( x > 0 && y < 0)
        cout << "Q4\n";
    
    return 0;
}