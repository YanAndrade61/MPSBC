#include<bits/stdc++.h>

using namespace std;

int main(){

	int e, t, p, total;

	cin >> e;
	
	while(e--){	
		cin >> t;
		total = 0;
		for(int i = 0; i < t; i++){
			cin >> p;
			total += (p*3);
		}
		total > (t*3) ? printf("precisa\n") : printf("nao precisa\n");
	}
}
