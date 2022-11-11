#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,num;

    while (true){
        
        cin >> N;
        if(!cin)break;

        vector<int> inicio;
        vector<int> fim;

        for (int i = 0; i < N; i++){
            cin >> num;
            inicio.push_back(num);
        }
        for (int i = 0; i < N; i++){
            cin >> num;
            fim.push_back(num);
        }
        num = 0;
        for (int i = N-1; i >= 1; i--){
            for (int j = i; j >= 1 ; j--){
                cout << inicio[j] << " " << fim[j] << endl;
                if(inicio[j] == fim[j]){
                    break;
                }
                else{
                    inicio[j],inicio[j-1] =;
                    num++;
                }
            }
        }
        
        cout << endl << num << "\n";
    }
    
    
    return 0;
}