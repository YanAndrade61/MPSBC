#include <bits/stdc++.h>

using namespace std;

int main(){

    int x1,x2,y1,y2, posLivre;
    int W,H,N;
    while (true){

        cin >> W >> H >> N;
        if(W == 0 && H == 0 && N == 0)break;

        vector<vector<bool>> m(H,vector<bool>(W,true));
        posLivre = 0;

        for (int i = 0; i < N; i++){
            cin >> x1 >> y1 >> x2 >> y2;

             for (int j = min(y1,y2)-1; j <= max(y1,y2)-1; j++){
                for (int k = min(x1,x2)-1; k <= max(x1,x2)-1; k++){
                    m[j][k] = false;
                }
            }
        }
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                posLivre += m[i][j];
            }
        }
        if(posLivre == 0)
            cout << "There is no empty spots.\n";
        else if(posLivre == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << posLivre << " empty spots.\n";
        
    }
    
    

    return 0;
}