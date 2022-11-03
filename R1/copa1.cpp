#include <bits/stdc++.h>

using namespace std;

int main(){

    int M,N;
    char ta,tb;
    queue<char> times;

    for (char c = 'A'; c <= 'P'; c++)
        times.push(c);
    
    for (int i = 0; i < 15; i++){
        cin >> M >> N;
        ta = times.front();times.pop();
        tb = times.front();times.pop();
        M > N ? times.push(ta) : times.push(tb);
    }
    cout << times.front() << "\n";

    return 0;
}