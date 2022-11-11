#include <bits/stdc++.h>

using namespace std;

bool fn(const pair<string,int> &x,const pair<string,int> &y){

    if(x.second != y.second){
        return x.second > y.second;
    }
    return x.first < y.first;

}

int main(){

    int N,teste=1;
    while(true){
        
        cin >> N;
        if(!cin)break;

        vector<pair<string,int> > alunos(N);

        cout << "Instancia " << teste++ << "\n";

        for (int i = 0; i < N; i++){
            cin >> alunos[i].first;
            cin >> alunos[i].second;
        }
        
        sort(alunos.begin(),alunos.end(),fn);

        cout << alunos[N-1].first << "\n";
        

    }

    return 0;
}