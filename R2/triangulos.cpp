#include <bits/stdc++.h>

using namespace std;

int count = 0;

double buscaBinaria(int L, int R, int vec[],int val){

    int mid = (L+R)/2;
    if(vec[mid] == val)
        return mid;
    if(L > R)
        return -1;
    if(val > vec[mid]) 
        return buscaBinaria(mid+1,R,vec,val);
    else
        return buscaBinaria(L,mid-1,vec,val);
            
}

int main(){

    int N,triangulos,dist,arco;

    while(true){

        cin >> N;
        if(!cin)break;

        int seq[N+1];
        triangulos = 0;
        seq[0] = 0;
        for (int i = 1; i < N+1; i++){
            cin >> dist;
            seq[i] = seq[i-1] + dist;
        }
        if(seq[N]%3 != 0) 
            cout << "0\n";
        else{
            arco = seq[N]/3;
            for (int i = 0; i < N; i++){
                if(buscaBinaria(0,N-1,seq,seq[i]+arco) != -1)
                    if(buscaBinaria(0,N-1,seq,seq[i]+(arco*2)) != -1)
                        triangulos++;
            }
            cout << triangulos << "\n";
        }
    }
    return 0;
}