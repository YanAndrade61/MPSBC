#include <bits/stdc++.h>

using namespace std;

int fatorial(int pos, vector<int> &fat){

    if(pos < fat.size()){
        return fat[pos];        
    }
    else{
        fat.push_back(fatorial(pos-1,fat)*pos);
        return fat[pos];
    }
}

int main(){

    int N,M;
    vector<int> fat(1,1);
    
    while (true){
        cin >> N >> M;
        if(!cin)break;
        cout << fatorial(N,fat) + fatorial(M,fat);
    
    }
    
    return 0;
}