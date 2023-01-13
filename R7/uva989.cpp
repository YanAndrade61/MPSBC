#include<bits/stdc++.h>
#define MAX_N 9

using namespace std;

int n;
int sol;
int tab[MAX_N][MAX_N];


bool verify(int num, int x, int y){
	
	//if(num == 0)return true;
	
	for(int i = 0; i < n*n; i++){
		if(i != y && tab[x][i] == num)return false;
		if(i != x && tab[i][y] == num)return false;
	}
	for(int i = (x - x%n); i < (x - x%n)+n; i++){
		for(int j = (y - y%n); j < (y - y%n)+n; j++){
			if(i != x && j != y && tab[i][j] == num)return false;
		}
	}
	return true;
}

bool check(){

	for(int i = 0; i < n*n; i++){
		for(int j = 0; j < n*n; j++){
			if(tab[i][j] != 0 && !verify(tab[i][j],i,j)){
			
				printf("%d %d %d\n",tab[i][j],i,j);
				return false;
			}
		}
	}	
	
	return true;
}

int solve(int x, int y){

	if(x >= n*n && sol == 0){
		sol = 1;
		for(int i = 0; i < n*n; i++){
			for(int j = 0; j < n*n; j++){
				printf("%d ",tab[i][j]);
			}
			printf("\n");
		}	
		printf("\n");
		return 0;
	}
	if(y >= n*n)
		solve(x+1, 0);
		
	if(tab[x][y] != 0)
		solve(x,y+1);
	
	for(int d = 1; d <= 9 && sol == 0; d++){
		if(verify(d,x,y)){
			tab[x][y] = d;
			solve(x,y+1);
			tab[x][y] = 0;	
		}
	}
	
	return 0;
}


int main(){

	int num;
	
	while(true){
	
		cin >> n;
		if(!cin)break;
		sol = 0;		
		for(int i = 0; i < n*n; i++){
			for(int j = 0; j < n*n; j++){
				cin >> num;
				tab[i][j] = num;
			}
		}	
		if(check())
			solve(0,0);
		if(sol == 0)
			printf("NO SOLUTION\n\n");
		
	}
	
	
	return 0;
}
