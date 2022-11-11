#include <bits/stdc++.h>

using namespace std;


int busca(int ini,int fim,int x,vector<int> seq){

    int mid = (ini+fim)/2;
    
    if(x == seq[mid])
        return mid;
    if(ini > fim)
        return -1;

    if(x > seq[mid])
        return busca(mid+1,fim,x,seq);
    else
        return busca(ini,mid-1,x,seq);

}

int main(){

    int N,Q,num;
    vector<int> seq;

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        seq.push_back(num);
    }
    for (int i = 0; i < Q; i++){
        cin >> num;
        cout << busca(0,N-1,num,seq) << "\n";
    }
    


    return 0;
}