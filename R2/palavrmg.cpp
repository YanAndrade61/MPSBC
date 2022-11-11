#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,ord=1;
    string s;
    cin >> N; 
    for (int i = 0; i < N; i++){
        cin >> s;
        ord = 1;
        for (int j = 0; j < (int)s.length()-1; j++){
            if((int)tolower(s[j]) >= (int)tolower(s[j+1])){
                ord = 0;
                break;
            }
        }
        cout << s << ": ";
        ord ? cout << "O\n" : cout << "N\n";
    }

    return 0;
}