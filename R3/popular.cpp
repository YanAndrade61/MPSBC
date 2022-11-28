#include <bits/stdc++.h>

using namespace std;

int main(){

	int N,v;
	
	while(true){
	
		cin >> N;
		if(N==0)break;
		
		vector<int> votos(N,0);
		
		for(int i = 0; i < N; i++){
			for(int j=0; j<N; j++){
				cin >> v;	
				votos[j] += v;
			}
		}
		sort(votos.rbegin(),votos.rend());
		cout << votos[0] << "\n";
	}	
	return 0;
}
