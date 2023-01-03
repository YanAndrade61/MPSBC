#include<bits/stdc++.h>

using namespace std;

int farida(int row[], int n){
	
	if(n == 1)
		return row[0];
	row[2] += row[0];
	for(int i = 3; i < n; i++){
		row[i] += max(row[i-2], row[i-3]);
	}
	return max(row[n-1],row[n-2]);		
}

int main(){

	int n, m;
	
	while(true){
	
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		int row[n];
		int col[m];
		for(int i=0; i < m; i++){
			for(int j=0; j < n; j++){
				cin >> *(row+j);
			}
			col[i] = farida(row,n);
		}
		printf("%d\n",farida(col,m));	
	}
}
