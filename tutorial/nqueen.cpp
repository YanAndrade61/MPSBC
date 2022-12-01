#include <bits/stdc++.h>

using namespace std;


bool isSafe(vector<vector<bool>> &tab, int N, int row, int col){

	int i,j;
	
	for(i=col; i >= 0; i--)
		if(tab[row][i])
			return false;

	for( i=row, j = col; i >= 0 && j >= 0; i--,j--)
		if(tab[i][j])
			return false;

	for( i=row, j = col; i < N && j >= 0; i++,j--)
		if(tab[i][j])
			return false;
	
	return true;
}

bool nQueen(vector<vector<bool>> &tab, int N, int col){


	int i;
	if(col >= N)
		return true;
	
	for(i = 0; i < N; i++){
	
		if(isSafe(tab, N, i, col)){
		
			tab[i][col] = 1;
			
			if(nQueen(tab,N,col+1))
				return true;
			
			tab[i][col] = 0;
		}
	}
	return false;

}

int main(){

	int N;
	
	cin >> N;
	
	vector<vector<bool>> tab(N,vector<bool>(N,false));	
	
	nQueen(tab,N,0);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << tab[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
