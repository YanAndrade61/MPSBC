#include <bits/stdc++.h>

using namespace std;


int main(){

    int teste,a,b,x,s;
    queue<int>dados,solv,res;

    cin >> teste;
    cin >> a;
    solv.push(a);
    for (int i = 0; i < teste; i++){
        cin >> a;
        if((int)dados.size() > 1)
            
        s = solv.front();solv.pop();
        x = (s - a - b)/2;
        res.push(s); res.push(a+x); res.push(b+x);
        res.push(a); res.push(x); res.push(b);
        solv.push(a); solv.push(b);
        dados.push(a);    
    }

    return 0;
}