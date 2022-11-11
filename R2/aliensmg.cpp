#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    string s;
    while (true){
        
        cin >> N; 
        if(N == 0)break;
        
        set<string> ind;
        for (int i = 0; i < N; i++){
            cin >> s;
            sort(s.begin(),s.end());
            ind.insert(s);
        }   
        cout << (int)ind.size() << "\n";
    }
    
    return 0;
}