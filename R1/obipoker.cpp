#include <bits/stdc++.h>

using namespace std;

int main(){

    int teste=1,N,x;

    cin >> N;
    for (int i = 0; i < N; i++){
        cout << "Teste " << teste++ << "\n";

        vector<int> cartas(13,0);
        vector<int> par;        
        vector<int> quadra;        
        vector<int> trinca;        
        vector<int> seq;
        
        for (int j = 0; j < 5; j++){
            cin >> x;
            cartas[x-1] += 1;
        }

        for (int j = 0; j < 13; j++){
            if(cartas[j] > 0)
                seq.push_back(j+1);
            else if((int)seq.size() < 5)
                seq.clear();
            if(cartas[j] == 2)
                par.push_back(j+1);
            if(cartas[j] == 3)
                trinca.push_back(j+1);
            if(cartas[j] == 4)
                quadra.push_back(j+1);
        }
        
        
        if((int)seq.size()==5){
            cout << 200 + seq[0] << "\n";
        }
        else if((int)quadra.size() == 1){
            cout << 180 + quadra[0] << "\n";
        }
        else if((int)par.size() >= 1 && (int)trinca.size() == 1){
            cout << 160 + trinca[0] << "\n";
        }
        else if((int)trinca.size() == 1){
            cout << 140 + trinca[0] <<  "\n";
        }
        else if((int)par.size() == 2){
            cout << 3*par[1] + 2*par[0] + 20 << "\n";
        }
        else if((int)par.size() == 1){
            cout << par[0] << "\n";
        }
        else{
            cout << 0 << "\n";
        }
        cout << "\n";
    }
    

    return 0;
}