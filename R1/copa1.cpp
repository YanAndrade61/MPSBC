#include <bits/stdc++.h>

using namespace std;

int main(){

    int M, N;
    char ta, tb;
    queue<char> times;

    for (char c = 'A'; c <= 'P'; c++)
        times.push(c);
    
    for (int i = 0; i < 15; i++){
        
        ta = times.front();times.pop;
        ta = times.front();times.pop;
    }
    
        cin >> M >> N;
        M > N ? times.erase(times.begin()+partida+1) : times.erase(times.begin()+partida);

        partida++;
        qtd--;
    }
    cout << times[0] << "\n";

    return 0;
}