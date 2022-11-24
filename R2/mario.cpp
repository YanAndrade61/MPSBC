#include <bits/stdc++.h>

using namespace std;


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

    int N,L,tam,max,first_max,first,aux1,aux2;

    while(true){

        cin >> N >> L;
        if(N == 0 && L == 0)break;

        vector<int> seq;
        aux2 = 0;
        tam=0;
        for (int i = 0; i < L; i++){
            cin >> aux1;
            seq.push_back(aux1);
            if(aux1 - aux2 == 1){
                tam++;
            }
            else{
                tam = 1;
                first = aux1;
            }
            if(max < tam){
                max = tam;
                first_max = first;
            }
        }
        for()
        
    }
    return 0;
}