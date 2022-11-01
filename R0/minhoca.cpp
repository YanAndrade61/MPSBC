#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<int>>;

int main(){

    int N, M, val;
    cin >> N >> M;
    vector<int> row(N,0),col(M,0);    

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> val;
            row[i] += val;
            col[j] += val;
        }
    }        
    
    cout << max(*max_element(row.begin(),row.end()),*max_element(col.begin(),col.end())) << "\n";

    return 0;
}