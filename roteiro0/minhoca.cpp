#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<int>>;

int main(){

    int N, M, max=0,sum;    
    cin >> N >> M;

    matrix cel(N,vector<int>(M,0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> cel[i][j];
            
    //Max sum in row
    for (int i = 0; i < N; i++)
        if(max < accumulate(cel[i].begin(),cel[i].end(),0))
            max = accumulate(cel[i].begin(),cel[i].end(),0);

    //max sum in column
    for (int j = 0; j < M; j++){
        sum = 0;
        for (int i = 0; i < N; i++)
            sum += cel[i][j];
        if(max < sum)
            max = sum;
    }
    
    cout << max << "\n";

    return 0;
}