#include <bits/stdc++.h>

using namespace std;

int main(){

    char c;
    string s,res;    

    while(true){   
        cin >> c >> s;
        if(c == '0' && s == "0")break;

        res = "0";        
        for (int i = 0; i < (int)s.size(); i++){
            if(s[i] != c)
                res += s[i];
        }
        
        while((int)res.size() > 1 && res[0] == '0')
            res.erase(0,1);

        cout << res <<"\n";
    }
    return 0;
}