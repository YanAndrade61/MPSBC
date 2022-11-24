#include <bits/stdc++.h>

using namespace std;

int main(){

    int T,N,M;
    string jap;
    istringstream aux;

    cin >> T;
    for (int i = 0; i < T; i++){
        
        map<string,string> dicionario; 
        cin >> M >> N;

        for (int j = 0; j < M; j++){
            cin >> jap; 
            cin.ignore();
            getline(cin, dicionario[jap],'\n');
        }
        for (int j = 0; j < N; j++){

            getline(cin, jap);
            istringstream iss(jap);
            while ( iss >> jap )
                cout << (dicionario.find(jap) == dicionario.end() ? jap : dicionario[jap]) << ' ';
            cout << "\n";
        }
        

    }
    
    return 0;
}