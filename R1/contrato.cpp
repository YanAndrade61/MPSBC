#include <bits/stdc++.h>

using namespace std;

int main(){

    int cont;
    char c;
    string s;    

    while(true){

        cin >> c >> s;
        if(c == '0' && s == "0")break;

        cont = 0;
        for (int i = 0; i < (int)s.size(); i++){
            if(s[i] != c){
                if(s[i] == '0' && cont > 0)
                    cout << s[i];
                else if(s[i] != '0'){
                    cout << s[i];
                    cont++;
                }
            }
        }
        if(cont == 0)
            cout << '0';
        cout << "\n";
    }

    return 0;
}