#include <bits/stdc++.h>

using namespace std;

int r,c;
int passy[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int passx[] = { 0, 1, 1, 1, 0,-1,-1,-1};
char m[100][100] = {'.'};
int uso[100][100] = {0};
int achou;
string path = "ALLIZZWELL";

void passo(int i, int j, int pos){
	
	if(pos >= 10){
		achou = 1;		
		return;
	}
	if(uso[i][j] == 1 || i >= r || i < 0 ||j >= c || j < 0)
		return;
	
	if(m[i][j] == path[pos]){
		uso[i][j] = 1;
		for(int k=0; k < 8 && !achou; k++){
			passo(i+passy[k],j+passx[k],pos+1);
		}
		uso[i][j] = 0;
	}
	
	return;
}

int main(){

	int t;
	char aux;
	
	cin >> t;
	
	while(t--){
		
		cin >> r >> c;
		achou = 0;
		
		for(int i = 0; i < r ; i++){
			for(int j=0; j < c;j++){
				cin >> aux;
				m[i][j] = aux;
			}
		}
		
		for(int i = 0; i < r ; i++){
			for(int j=0; j < c;j++){
				passo(i,j,0);
				if(achou)break;
			}
			if(achou)break;
		}
		/*
		for(int i = 0; i < r ; i++){
			for(int j=0; j < c;j++){
				cout << uso[i][j] << " ";
			}
			cout << "\n";
		}
		*/
		
		if(achou)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
