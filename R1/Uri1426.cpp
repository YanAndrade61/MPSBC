#include <bits/stdc++.h>

using namespace std;


int main(){

    int teste,a,x,N=9;

    cin >> teste;
    for (int i = 0; i < teste; i++){

        vector<vector<int>> m(N,vector<int>(N,1));
        for (int j = 0; j < N; j += 2){
            for (int k = 0; k <= j; k += 2){
                cin >> a;
                m[j][k] = a;
            }    
        }
        for (int j = 0; j < 9; j += 2){
            for (int k = 0; k < j+1; k += 2){
                x = (m[j][k] - m[j+2][k] - m[j+2][k+2])/2;
                m[j+1][k] = x + m[j+2][k];
                m[j+1][k+1] = x + m[j+2][k+2];
                m[j+2][k+1] = x;
            }    
        }
        for (int j = 0; j < 9; j += 2){
            for (int k = 0; k <= j; k++){
                cout << m[j][k] << " ";
            }
            cout << endl;    
        }
    }

    return 0;
}