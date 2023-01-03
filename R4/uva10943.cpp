#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, k;
	
	while(true){
	
		cin >> n >> k;
		if(n == 0 && k == 0)break;
		
		if(k == 1){
			printf("1\n");
			continue;
		}
		
		long long int dp[k-1][n+1];
		
		for(int i = 0; i <= n; i++){
			dp[0][i] = i+1;
		}
		
		for(int i = 1; i < k-1; i++){
			for(int j = 0; j <= n; j++){
				if(j == 0) 
					dp[i][j] = 1;
				else 
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000;
				
			}
		}
		printf("%lld\n",dp[k-2][n]);
	}

}
