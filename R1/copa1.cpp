#include <bits/stdc++.h>

using namespace std;

int main(){

    int M, N, qtd=16, partida=0;
    vector<char> times;

    for (int i = 0; i < qtd; i++)
        times.push_back(char(65+i));
    
    while(qtd > 1){

        if(ceil(log2(qtd)) == floor(log2(qtd)))
            partida=0;

        cin >> M >> N;
        M > N ? times.erase(times.begin()+partida+1) : times.erase(times.begin()+partida);

        partida++;
        qtd--;
    }
    cout << times[0] << "\n";

    return 0;
}