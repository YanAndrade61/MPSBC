#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,num, sum, it = 1, achou=0;
    vector<int> a;

    while(true){

        cin >> N;
        if(!cin)break;

        cout << "\nInstancia " << it << "\n";

        for (int i = 0; i < N; i++){

            cin >> num;
            a.push_back(num);
            sum = accumulate(a.begin(),a.end(),0) - num;
            
            if(sum == num && achou == 0){
                cout << num << "\n";
                achou = 1;
            }    
        }
        if(!achou){
            cout << "nao achei\n";
        }

        achou = 0;
        a.clear();
        it++;
    }
    
    return 0;
}