#include <bits/stdc++.h>

using namespace std;

// int check(int tab[], int ans[],bool pecas[], int i1, int j1, int i2, int j2){

// 	int v1 = tab[i1*7+j1];
// 	int v2 = tab[i2*7+j2];
	
// 	if(ans[i1*7+j1] != 0 || ans[i2*7+j2] != 0)
// 		return -1;
	
// 	if(v1 > v2){
// 		if(pecas[v2*7+v1-v2] == false)
// 			return (v2*7+v1-v2);
// 	}
// 	else{
// 		if(pecas[v1*7+v2-v1] == false)
// 			return (v1*7+v2-v1);
// 	}
// 	return -1;
// }

// bool domino(int tab[],int ans[],bool pecas[],int i, int j, int *cont){

// 	int tenta;
// 	if(i >= 7){
// 		(*cont)++;
// 		return true;
// 	}
// 	if(j >= 8)
// 		domino(tab,ans,pecas,i+1,0,cont);
	
// 	if(ans[i*7+j] != 0)
// 		domino(tab,ans,pecas,i,j+1,cont);

// 	tenta = check(tab,ans,pecas,i,j,i,j+1);

// 	if (tenta != -1){
// 		pecas[tenta] = true;
// 		ans[i*7+j] = tenta+1;
// 		ans[i*7+j+1] = tenta+1;
		
// 		domino(tab,ans,pecas,i,j+1,cont);
		
// 		pecas[tenta] = false;
// 		ans[i*7+j] = 0;
// 		ans[i*7+j+1] = 0;
// 	}
// 	for (int i = 0; i < 7; i++)
// 	{
// 		for (int j = 0; j < 8; j++)
// 		{
// 			cout << ans[i*7+j] << " ";
// 		}
// 		cout << "\n";
// 	}
// 	cout << "\n";
	
// 	tenta = check(tab,ans,pecas,i,j,i+1,j);
	
// 	if (tenta != -1){
// 		pecas[tenta] = true;
// 		ans[i*7+j] = tenta+1;
// 		ans[(i+1)*7+j] = tenta+1;
		
// 		domino(tab,ans,pecas,i,j+1,cont);
		
// 		pecas[tenta] = false;
// 		ans[i*7+j] = 0;
// 		ans[(i+1)*7+j] = 0;
// 	}

// 	return false;

// }

int solve(int tab[7][8],int ans[7][8], vector<tuple<int,int,int>> pecas,int i, int j, int *cont){

	int m1,m2;
	vector<tuple<int,int,int>>::iterator it; 

	// for (int i = 0; i < 7; i++){
	// 	for (int j = 0; j < 8; j++){
	// 		cout << ans[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";
	
	// if(i >= 7 ){
	// 	*cont += 1;
	// 	return 1;
	// }
	if(*find(ans,ans+56,1) == ans+56){
		*cont += 1;
		return 1;
	}
	if(j >= 8)
		return solve(tab,ans,pecas,i+1,0,cont);
	if(ans[i][j] != 0)
		return solve(tab,ans,pecas,i,j+1,cont);
	
	//Horizontal
	if(ans[i][j+1] == 0){
		
		if(tab[i][j] > tab[i][j+1]){
			m1 = tab[i][j+1];
			m2 = tab[i][j];
		}else{
			m2 = tab[i][j+1];
			m1 = tab[i][j];
		}
		it = find(pecas.begin(),pecas.end(),make_tuple(0,m1,m2)); 
		if(it != pecas.end()){
			get<0>(*it) = 1;
			ans[i][j] = 1;
			ans[i][j+1] = 1;
			
			solve(tab,ans,pecas,i,j+2,cont);
			
			get<0>(*it) = 0;
			ans[i][j] = 0;
			ans[i][j+1] = 0;
		}
	}
	//Vertical
	if(ans[i+1][j] == 0){
		if(tab[i][j] > tab[i+1][j]){
			m1 = tab[i+1][j];
			m2 = tab[i][j];
		}else{
			m2 = tab[i+1][j];
			m1 = tab[i][j];
		}
		it = find(pecas.begin(),pecas.end(),make_tuple(0,m1,m2)); 
		if(it != pecas.end()){
			get<0>(*it) = 1;
			ans[i][j] = 1;
			ans[i+1][j] = 1;
			
			solve(tab,ans,pecas,i,j+1,cont);
			
			get<0>(*it) = 0;
			ans[i][j] = 0;
			ans[i+1][j] = 0;
		}
	}
	return 0;
}


int main(){

	vector<tuple<int,int,int>> pecas;
	int tab[7][8], ans[7][8], cont, N;
	int n;
	cin >> N;
	
	for(int k = 0; k < N; k++){
		cont = 0;
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 8; j++){
				cin >> n;
				tab[i][j] = n;
				ans[i][j] = 0;
			}
		}
		for (int i = 0; i < 7; i++)
			for (int j = i; j < 7; j++)
				pecas.push_back(make_tuple(0,i,j));
		
		solve(tab,ans,pecas,0,0,&cont);
		cout << "Teste " << k+1 << "\n";
		cout << cont << "\n\n";
		
	}
	
	return 0;
}
