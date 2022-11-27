#include <bits/stdc++.h>

using namespace std;


double buscaBinaria(int L, int R, int vec[],int val){

    int mid = (L+R)/2;
    if(vec[mid] == val)
        return mid;
    if(L > R)
        return mid;
    if(val > vec[mid]) 
        return buscaBinaria(mid+1,R,vec,val);
    else
        return buscaBinaria(L,mid-1,vec,val);
            
}

int main(){

    int N,L,pos,max;

    while(true){

        cin >> N >> L;
        if(N == 0 && L == 0)break;

        int seq[L];
        max = 0;
        for (int i = 0; i < L; i++)
            cin >> *(seq+i);
        
        for (int i = 0; i < L; i++){
            pos = buscaBinaria(0,L-1,seq,seq[i]+N-1);
            max = max < pos-i+1 ? (pos-i+1) : max;
        }
        cout << N-max << "\n";
    }
    return 0;
}