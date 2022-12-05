#include <bits/stdc++.h>

using namespace std;

int main(){

	int c,f,teste=1;
	
	while(true){
	
		cin >> c >> f;
		if(c == 0 && f == 0)break;
		
		int cmp[f], dscp[f];
		int qtd[f+1][c+1] = {};	
		for(int i=0; i < f; i++)
			cin >> *(cmp+i) >> *(dscp+i);
		for(int i=0; i < f+1; i++){
			for(int j=0; j < c+1;j++){
				if(i == 0 || j == 0)continue;
				if(cmp[i-1] <= j){
					qtd[i][j] = max(qtd[i-1][j],dscp[i-1]+qtd[i-1][j-cmp[i-1]]);
				}
				else{
					qtd[i][j] = qtd[i-1][j];
				}
			}
		}
		printf("Teste %d\n%d\n\n",teste++,qtd[f][c]);
		 
	}	
}
