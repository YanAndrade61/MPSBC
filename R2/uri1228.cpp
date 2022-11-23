#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,over,i,pos;
    while(true){
        
        cin >> N; 
        if(!cin)break;
    
        int largada[N],chegada[N];
    
        for (int i = 0; i < N; i++)
            cin >> *(largada+i);
        for (int i = 0; i < N; i++)
            cin >> *(chegada+i);
    
        over=0;
        for (int i = 0; i < N; i++){
            while (largada[i] != chegada[i]){
                
                pos = find(largada,largada+N,chegada[i])-largada;
                swap(largada[pos-1],largada[pos]);
                over++;
            }
        }
        cout << over << "\n";
    }
    return 0;
}