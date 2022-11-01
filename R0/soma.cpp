#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    int sum = 0, num;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> num;
        sum += num;
    }
    cout << sum << "\n";
    
    return 0;
}