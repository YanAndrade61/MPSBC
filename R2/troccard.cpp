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

    int nA,nB;

    while(true){

        cin >> nA >> nB;
        if(nA == 0 && nB == 0)break;

        int a[nA], b[nB];
        set<int> subA; 
        set<int> subB; 
        
        for (int i = 0; i < nA; i++){
            cin >> *(a+i);
        }
        for (int i = 0; i < nB; i++){
            cin >> *(b+i);
        }
        for (int i = 0; i < nA; i++){
            if(buscaBinaria(0,nB,b,a[i]) == -1){
                subA.insert(a[i]);
            }
        }
        for (int i = 0; i < nB; i++){
            if(buscaBinaria(0,nA,a,b[i]) == -1){
                subB.insert(b[i]);
            }
        }
        cout << (subA.size() > subB.size() ? subB.size() : subA.size()) << "\n"; 
    }
    return 0;
}