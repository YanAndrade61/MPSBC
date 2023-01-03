#include <bits/stdc++.h>

using namespace std;

int main(){

	int m,n,t;
	
	while(true){
	
		cin >> m >> n >> t;
		if(!cin)break;
		
		int tab[t+1];
		fill(tab,tab+t+1,-1);
		tab[0]=0;

		for(int i = 0 ; i<=t;i++){
			
			if(m <= i && tab[i-m] != -1)
				tab[i] = tab[i-m]+1;
			if(n <= i && tab[i-n] != -1)
				tab[i] = max(tab[i],tab[i-n]+1);
		}
		if(tab[t] != -1){
			printf("%d\n",tab[t]);
		}
		else{
			for(int i = t; i >= 0; i--){
				if(tab[i] != -1){
					printf("%d %d\n",tab[i],t-i);
					break;
				}
			}
		}
	}


}
