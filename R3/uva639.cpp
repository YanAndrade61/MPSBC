#include <bits/stdc++.h>

using namespace std;


bool isSafe(char tab[], int N, int row, int col){
	
	if(tab[row*N+col] == 'X')
		return false;
	for(int i = col; i >= 0;i--){
		if(tab[(row*N)+i] == 'r')
			return false;
		else if(tab[(row*N)+i] == 'X')
			break;
	}
	
	for(int i = row; i >= 0;i--){
		if(tab[(i*N)+col] == 'r')
			return false;
		else if(tab[(i*N)+col] == 'X')
			break;
	}
	return true;
}


bool nRook(char tab[], int N, int row, int col,int cont,int* max){

	if(col >= N || row >= N)
		return true;
		
	for(int i = row; i < N;i++){
	
		if(isSafe(tab,N,i,col)){
		
			tab[(i*N)+col] = 'r';
			if(cont+1 > *max)
				*max = cont+1;
	
			if(nRook(tab,N,i+1,col,cont+1,max)){
				if(nRook(tab,N,0,col+1,cont+1,max))
					return true;
			}
			else if(nRook(tab,N,0,col+1,cont+1,max))
				return true;
		
			tab[(i*N)+col] = '.';			
		}
	}
	return false;
}

int main(){
	
	int N,*max;
	char c;
	while(true){
	
		cin >> N;
		if(N == 0)break;
		
		char tab[N*N];
		*max = 0;
		for(int i = 0;i<N;i++){
			for(int j = 0; j<N; j++){
				cin >> c;
				tab[(i*N)+j] = c;
			}
		}
		
		nRook(tab,N,0,0,0,max);
		
		cout << *max << "\n";
	}	

	return 0;
}
