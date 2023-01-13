#include<bits/stdc++.h>
#define MAX_M 61

using namespace std;

int main(){

	int n, m, cont, aux;
	char l;
	int botas[MAX_M];

	while(true){
	
		cin >> n;
		if(!cin)break;
		
		cont = 0;
		for(int i = 0; i < MAX_M; i++)
			botas[i] = 0;
		
		for(int i = 0; i < n; i++){
			cin >> m >> l;
			aux = abs(botas[m]);
			botas[m] += (l == 'D' ? 1 : -1);
			if(abs(botas[m]) < aux)cont++;
		}
		
		printf("%d\n",cont);
	
	}

	return 0;
}
