#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,num,pos;
    vector<int> start,end2;
    vector<int> :: iterator it;
    while (true){

        cin >> N;
        if(!cin)break;

        for (int i = 0; i < N; i++){
            cin >> num;
            start.push_back(num);
        }
        for (int i = 0; i < N; i++){
            cin >> num;
            it = find(start.begin(),start.end(),num);
            if(it != start.end()){
                for (int j = ; j < count; j++)
                {
                    /* code */
                }
                
            }
        }
        
        
    }
    
      
    return 0;
}