#include <bits/stdc++.h>

using namespace std;

int main(){

	int m,n;
	
	while(true){
	
		cin >> m >> n;
		if(m== 0)break;
		
		int moedas[n];
		int qtd[m+1];
		fill(qtd,qtd+m+1,100000);	
		for(int i=0; i < n; i++)
			cin >> *(moedas+i);
			
		qtd[0] = 0;
		for(int i=1; i < m+1; i++){
			for(int j=0; j <n;j++){
				if(moedas[j] <= i && qtd[i-moedas[j]]+1 < qtd[i])
					qtd[i] = qtd[i-moedas[j]]+1;
			}
		}
		if(qtd[m] == 100000)
			printf("Impossivel\n");
		else
			printf("%d\n",qtd[m]);
	}	

}
