#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, cont=0;
	cin >> n;
	
	int enemy[n];
	int ally[n];
	
	for(int i = 0; i < n; i++)
		cin >> *(enemy+i);
	for(int i = 0; i < n; i++)
		cin >> *(ally+i);
	
	sort(enemy,enemy+n);
	sort(ally,ally+n);
	
	for(int i = 0; i < n; i++){
		if(ally[i] > enemy[cont])
			cont++;			
	}
	printf("%d\n",cont);

	return 0;
}
