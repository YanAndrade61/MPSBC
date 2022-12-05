#include <bits/stdc++.h>

using namespace std;

unsigned int dir[21];
int M, D, T, mini;


void solve(int i, unsigned int mask, int seq){

	int qtd;
	if(i >= D) return;
	
	qtd = __builtin_popcount(mask | dir[i]);
	if(qtd >= M){
		if( seq < mini) mini = seq;
	}
	else{
		solve(i+1,mask,seq);
		solve(i+1,(mask | dir[i]),seq+1);
	}
}

int main(){

	int aux,C;
	
	cin >> T;
	
	while(T--){
		cin >> M >> D;	
		mini = INT_MAX;
		
		for(int i=0; i < D; i++){
			cin >> C;
			dir[i]=0;
			for(int j=0; j < C; j++){
				cin >> aux;
				dir[i] |= 1u << aux;
			}
		}
		
		solve(0,0u,1);
		
		if(mini == INT_MAX)
			cout << "Desastre!\n";
		else
			cout << mini << "\n";		
	}
}
