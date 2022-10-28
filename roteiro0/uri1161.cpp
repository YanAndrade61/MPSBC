#include <bits/stdc++.h>

using namespace std;

int main(){

    unsigned long long int N,M,fatN,fatM;
    
    while (true){
        
        cin >> N >> M;
        if(!cin)break;
        
        fatM = fatN = 1;
        for (int i = N; i > 0; i--)
            fatN *= i;
        for (int i = M; i > 0; i--)
            fatM *= i;
        cout << fatN + fatM << "\n";

    }
    
    return 0;
}