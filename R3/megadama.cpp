#include <bits/stdc++.h>

using namespace std;

int n,m,maxi=0;
int diagx[] = {-1,1,-1,1};
int diagy[] = {1,1,-1,-1};

int checkSpace(int tab[], int i, int j, int x){
	
	if(i >= n || j >= m || i < 0 || j < 0)return 0;
	
	if(tab[i*m+j] == x)return 1;
	else return 0;

}
void solve(int tab[],int i, int j,int cap){

	if(i >= n || j >= m || i < 0 || j < 0)return;
	
	if(cap > maxi)maxi=cap;
	
	for(int k =0; k < 4; k++){
	
		if(checkSpace(tab,i+diagx[k],j+diagy[k],2)){
			if(checkSpace(tab,i+2*diagx[k],j+2*diagy[k],0)){	
				tab[i*m + j] = 0;
				tab[(i+diagx[k])*m + j+diagy[k]] = 0;
				
				solve(tab,i+2*diagx[k],j+2*diagy[k],cap+1);
				
				tab[(i+2*diagx[k])*m + j+2*diagy[k]] = 0;
				tab[i*m + j] = 1;
				tab[(i+diagx[k])*m + j+diagy[k]] = 2;
			}	
		}
	}
}

int main(){
	
	int aux;

	while(true){
		cin >> n >> m;
		if(n==0 && m == 0)break;
		maxi = 0;
		int tab[n*m] = {0};

		for(int i = 0; i < n; i++){
			for(int j = i%2; j < m;j += 2){
				cin >> aux;
				tab[i*m+j] = aux; 
			}
		}
		for(int i =0; i < n; i++){
			for(int j=i%2; j < m; j += 2){
				if(tab[i*m+j] == 1)
					solve(tab,i,j,0);
			}
		}	
		cout << maxi << "\n"; 
	}
	return 0;
}
