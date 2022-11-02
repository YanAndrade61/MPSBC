#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,a=0,b=1,sum;
    cin >> N;
    cout << a << " " << b;
    for (int i = 2; i < N; i++){
        sum = a+b;
        a = b;
        b = sum;
        cout << " " << sum;
    }
    cout << "\n";
    return 0;
}