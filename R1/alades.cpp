#include <bits/stdc++.h>

using namespace std;


int main(){

    int H1,M1,H2,M2,min;

    while (true){

        cin >> H1 >> M1 >> H2 >> M2;
        if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)break;

        if((H2 == H1 && M1 > M2) || (H1 > H2))
            H2 += 24;
        min = (H2*60 + M2) - (H1*60 + M1);
        cout << min << endl; 
    }
    
    return 0;
}