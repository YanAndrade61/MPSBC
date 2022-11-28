#include <bits/stdc++.h>

using namespace std;

int main(){


	int N,moves,acc;
	
	while(true){
	
		cin >> N;
		if(N==-1)break;
		
		int candies[N];
		moves = 0;
		acc = 0;
		for(int i = 0;i<N;i++){
			cin >> *(candies+i);
			acc += candies[i];
		}
		
		if(acc%N != 0)
			cout << "-1\n";
		else{
			for(int i=0; i < N ; i++){
				if(acc/N - candies[i] > 0)
					moves += acc/N - candies[i];
			}
			cout << moves << "\n";
		}
	}

	return 0;
}
