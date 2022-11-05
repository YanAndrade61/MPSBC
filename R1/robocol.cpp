#include <bits/stdc++.h>

using namespace std;

map<char,tuple<int, int>> orient;
map<char,map<char, char>> coord;

int main(){

    int N,M,S,ri,rj,qtd=0;
    char c,dir;

    orient['N'] = make_tuple(-1,0);
    orient['S'] = make_tuple(1,0);
    orient['O'] = make_tuple(0,-1);
    orient['L'] = make_tuple(0,1);
    coord['N']['D'] = 'L'; coord['N']['E'] = 'O';
    coord['S']['D'] = 'O'; coord['S']['E'] = 'L';
    coord['O']['D'] = 'N'; coord['O']['E'] = 'S';
    coord['L']['D'] = 'S'; coord['L']['E'] = 'N';

    while (true)
    {
        cin >> N >> M >> S;
        if(N == 0 && M == 0 && S == 0)break;

        vector<vector<char>> arena(N,vector<char>(M,'0'));

        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                cin >> c;
                arena[i][j] = c;
                if(c != '.' && c != '*' && c != '#'){
                    ri = i;
                    rj = j;
                    dir = c;
                }
            }            
        }
        
        qtd = 0;
        for (int i = 0; i < S; i++){
            cin >> c;
            if(c == 'F'){
                int a,b;
                a = ri + get<0>(orient[dir]);
                b = rj + get<1>(orient[dir]); 
                if(a == N || a < 0 || b == M || b < 0 || arena[a][b] == '#')
                    continue; 
                arena[ri][rj] = '.';
                ri = a; 
                rj = b;
                if(arena[ri][rj] == '*'){
                    qtd++;
                    arena[ri][rj] = dir;
                }
            }
            else{
                dir = coord[dir][c];
            }
        }
        cout << qtd << "\n";
        
    }
    
    
    return 0;
}