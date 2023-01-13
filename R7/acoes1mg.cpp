#include<bits/stdc++.h>

using namespace std;

int n, k;

int solve(int part){

	if(part <= k)
		return 1;
	return solve(floor(part/2.0)) + solve(ceil(part/2.0)); 
}


int main(){

	while(true){
	
		cin >> n >> k;
		if(n == 0 && k == 0)break;
		
		printf("%d\n",solve(n));
	}


}
