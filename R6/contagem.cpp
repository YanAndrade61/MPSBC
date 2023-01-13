#include<bits/stdc++.h>

using namespace std;

int main(){

	string pattern;
	int L, test=1;
	long long int cont;
	
	while(true){
	
		cin >> pattern;
		if(!cin)break;
		cont = 0;
		L = pattern.length();
		for(int i = 0; i < L; i++){
			if(pattern[i] == 'b'){
				cont += pow(2, L-i-1);
			}
		}
		printf("Palavra %d\n%lld\n\n",test++,cont);	
	}


}
