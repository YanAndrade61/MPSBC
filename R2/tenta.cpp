#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,num;
    vector<int> v;
    while(true){
        cin >> N;
        if(N == 0)break;
        for (int i = 0; i < N; i++){
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        do{
            cout << v[0];
            int tam = (int)v.size();
            for (int i = 1; i < tam; i++){
                cout << " " << v[i];                
            }
            cout << "\n";
        }while(next_permutation(v.begin(),v.end()));
        cout << "\n";
        v.clear();

    }

    return 0;
}