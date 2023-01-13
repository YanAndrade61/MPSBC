#include<bits/stdc++.h>

using namespace std;

int main(){

	int t, n, pnt, total;
	string time;
	
	while(true){
	
		cin >> t >> n;
		if(t == 0 && n == 0)break;
		total = n*3;
		
		for(int i = 0; i < t; i++){
			cin >> time >> pnt;
			total -= pnt;
		}
		printf("%d\n",total);
	}

	return 0;
}
