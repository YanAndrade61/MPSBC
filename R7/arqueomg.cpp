#include<bits/stdc++.h>

using namespace std;

int main(){

	int k, nasc, mort;
	
	cin >> k;
	
	while(k--){
	
		cin >> nasc >> mort;
		int idade = abs(mort-nasc);
		printf("%d\n", (nasc*mort < 0 ? idade-1 : idade));
	}

}
