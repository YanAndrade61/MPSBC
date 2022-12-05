#include <bits/stdc++.h>

using namespace std;

int solve(int tab[7][8],int ans[7][8], vector<tuple<int,int,int>> pecas,int i, int j, int *cont){

	int m1,m2;
	vector<tuple<int,int,int>>::iterator it; 

	if(i >= 7 ){
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

	
    int tab[7][8], ans[7][8], cont, N;
    vector<tuple<int,int,int>> pecas;
    int n;
	cin >> N;
		
    for (int i = 0; i < 7; i++){
        for (int j = i; j < 7; j++){
            pecas.push_back(make_tuple(0,i,j));  
        }
    }
	for(int k = 0; k < N; k++){
		cont = 0;
		
        for (int i = 0; i < 7; i++){
			for (int j = 0; j < 8; j++){
				cin >> n;
				tab[i][j] = n;
				ans[i][j] = 0;
			}
		}
		solve(tab,ans,pecas,0,0,&cont);
		cout << "Teste " << k+1 << "\n";
		cout << cont << "\n\n";
		
	}
	
	return 0;
}
