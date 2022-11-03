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
        ta = times.front();times.pop();
        tb = times.front();times.pop();
        M > N ? times.push(ta) : times.push(tb);
    }
    cout << times.front() << "\n";

    return 0;
}