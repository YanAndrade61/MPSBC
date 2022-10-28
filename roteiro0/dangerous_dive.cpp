#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,R,id;
    vector<int> vol;

    while (true){
        
        cin >> N >> R;
        if(!cin)break;

        for (int i = 0; i < N; i++)
            vol.push_back(i+1);

        for (int i = 0; i < R; i++){
            cin >> id;
            vol[id-1] = 0;
        }
        if(R == N)
            cout << "*";

        for(int id: vol)
            if(id != 0)
                cout << id << " ";
        
        cout << "\n";
        vol.clear();
    }
    
    return 0;
}