#include <bits/stdc++.h>

using namespace std;


int main(){

    int N,borda,mid,num=1;

    while(true){
        cin >> N;
        if(N == 0)break;

        vector<vector<int>> matrix(N,vector<int>(N,1));
        
        mid = N%2 == 0 ? N/2 : (N/2)+1;
        for (int i = 0; i < mid; i++){    
            borda = (N-1)-i;
            num=1;
            for (int j = i; j < borda; j++){
                matrix[i][j] = num;
                matrix[j][i] = num;
                matrix[borda][j] = N-j-i;
                matrix[j][borda] = N-j-i;
                num++;
            }
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if(j != 0)
                    cout << " ";

                cout << setw(3) << matrix[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}