#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    size_t pos;
    string partner,txt;
    cin >> N; 
    for (int i = 0; i < N; i++){
        cin >> partner >> txt;
        txt += txt;

        pos = txt.find(partner);
        if(pos != string::npos){
            cout << "S\n";
            continue;
        }
        
        reverse(txt.begin(),txt.end());
        pos = txt.find(partner);
        if(pos != string::npos){
            cout << "S\n";
            continue;
        }
        cout << "N\n";
    }

    return 0;
}