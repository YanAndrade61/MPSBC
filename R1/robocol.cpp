#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    while (true){

        cin >> N;
        if(N == 0)break;

        cout << "f91(" << N << ") = " << (N >= 101 ? N-10 : 91) << endl;
    }
    
    return 0;
}