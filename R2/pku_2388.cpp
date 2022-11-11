#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,num;
    vector<int> v;
    cin >> N; 
    for (int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cout << v[N/2] << "\n";

    return 0;
}