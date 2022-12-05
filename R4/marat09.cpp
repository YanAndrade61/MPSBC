#include <bits/stdc++.h>

using namespace std;

int main(){

	char ans='S';
	int n,m,aux1,aux2=0;
	int dist=42195;
	
	cin >> n >> m;
	
	for(int i=0; i < n;i++){
		cin >> aux1;
		if(aux1-aux2 > m){
			ans='N';
			break;
		}
		aux2=aux1;
	}
	if(dist-aux2 > m)ans='N';
	printf("%c\n",ans);

	return 0;
}
