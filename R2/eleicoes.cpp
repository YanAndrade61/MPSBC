#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,voto,max=0,vencedor;
    
    map<int,int> urna; 

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> voto;
        if(urna[voto] > 0)
            urna[voto] += 1;
        else
            urna[voto] = 1;

        if(urna[voto] > max){
            vencedor = voto;
            max = urna[voto];
        }
    }
    cout << vencedor << "\n";
    return 0;
}