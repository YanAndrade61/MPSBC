#include <bits/stdc++.h>

using namespace std;

int check(int tab[], int ans[],bool pecas[], int i1, int j1, int i2, int j2){

	int v1 = tab[i1*7+j1];
	int v2 = tab[i2*7+j2];
	
	if(ans[i1*7+j1] != 0 || ans[i2*7+j2] != 0)
		return -1;
	
	if(pecas[v1*7+v2-v1] == false)
		return (v1*7+v2-v1);
	
	if(pecas[v2*7+v1-v2] == false)
		return (v2*7+v1-v2);
	
	return -1;
}

bool domino(int tab[],int ans[],bool pecas[],int i, int j, int *cont){

	int tenta;
	if(i >= 8){
		(*cont)++;
		return true;
	}
	if(j >= 7)
		return domino(tab,ans,pecas,i+1,0,cont);
	
	tenta = check(tab,ans,pecas,i,j,i,j+1);
	if( tenta == -1)
		return false;
	else{
		pecas[tenta] = true;
		ans[i*7+j] = tenta+1;
		ans[i*7+j+1] = tenta+1;
		return domino(tab,ans,pecas,i,j+2,cont);
		pecas[tenta] = false;
		ans[i*7+j] = 0;
		ans[i*7+j+1] = 0;
	}
	
	tenta = check(tab,ans,pecas,i,j,i+1,j);
	if( tenta == -1)
		return false;
	else{
		pecas[tenta] = true;
		ans[i*7+j] = tenta+1;
		ans[(i+1)*7+j] = tenta+1;
		return domino(tab,ans,pecas,i,j+1,cont);
		pecas[tenta] = false;
		ans[i*7+j] = 0;
		ans[i*7+j+1] = 0;
	}
	
	return false;

}

int main(){

	bool pecas[28];
	int tab[56], ans[56], cont, test;
	
	cin >> test;
	
	for(int i = 0; i < test; i++){
		cont = 0;	
		for(int i=0; i < 28; i++)
			pecas[i] = false;	
		
		for(int j=0;j<56;j++)
			cin >> *(tab+i);

		domino(tab,ans,pecas,0,0,&cont);
		cout << "Teste " << cont << "\n";
		cout << cont << "\n\n";
		
	}
	
	
	return 0;
}
