#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,cont=0;
    cin >> N;
    int a[N],b[N],c[N],d[N];
    vector<int> ab;
    pair<vector<int>::iterator, vector<int>::iterator> bounds;

    for (int i = 0; i < N; i++){
        cin >> *(a+i) >> *(b+i) >> *(c+i) >> *(d+i);
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ab.push_back(a[i]+b[j]);

    sort(ab.begin(),ab.end());

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int temp = -(c[i]+d[j]);
<<<<<<< HEAD
            bounds.first = lower_bound();
            bounds = equal_range();
=======
            bounds = equal_range(ab.begin(),ab.end(),temp);
>>>>>>> c71a8a34fdbb61f00e04c9e0066fd1eb39bfa300
            cont += bounds.second - bounds.first;
        }
    }

    cout << cont << "\n";
    
    return 0;
}