#include <bits/stdc++.h>

using namespace std;
int char2dec(char c);

int main(){

    string palavra;
    int n;
    bool ehPrimo;

    while (true){
        
        cin >> palavra;
        if(!cin)break;
        
        n= 0;
        ehPrimo = true;
        for(char c: palavra){
            n += char2dec(c);
        }

        for (int i = 2; i < n; i++){
            if(n%i == 0){
                ehPrimo= false;
                break;
            }
        }
        ehPrimo ? cout << "It is a prime word.\n" : cout << "It is not a prime word.\n"; 
    }
    return 0;
}

int char2dec(char c){

    if(c > 'Z')
        return c - 96;
    return c - 65 + 27;
}