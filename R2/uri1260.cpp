#include <bits/stdc++.h>

using namespace std;

int main(){

    float total;
    string s;
    int N;
    cin >> N;
    cin.get();
    getline(cin,s);

    cout << fixed << setprecision(4);

    for (int i = 0; i < N; i++){
        
        map<string,int> arvores;
        total = 0;
        while(getline(cin, s) and s[0] != '\0'){
            
            if(arvores.find(s) == arvores.end())
                arvores[s] = 1;
            else
                arvores[s] += 1;
            total++;
        }
        for (auto it = arvores.begin(); it != arvores.end(); it++)
            cout << it->first << " " << it->second/total*100.0 << "\n";
        
        i < N-1 ? cout << "\n" : cout << "";
    }
    
    return 0;
}