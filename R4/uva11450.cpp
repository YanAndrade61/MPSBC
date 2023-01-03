#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m, c, k, seg;

	cin >> n;
	
	while(n--){
	
		cin >> m >> c;
		int dp[c+1][m+1];
		
		for(int i = 0; i <= c; i++)
			for(int j = 0; j <= m; j++)
				dp[i][j] = 0;
		dp[0][0] = 1;
				
		for(int i = 1; i <= c; i++){
			cin >> k;
			int wt[k];
			for(int j = 0; j < k; j++)
				cin >> *(wt+j);
			
			for(int j = 0; j <= m; j++){	
				for(int p = 0; p < k; p++){
					if(wt[p] <= j && dp[i-1][j-wt[p]] == 1)
						dp[i][j] = 1;
				}
			}
		}
		seg = 0;
		for(int i = m; i >= 0; i--){
			if(dp[c][i] != 0){
				printf("%d\n",i);
				seg = 1;
				break;
			}
		}
		if(!seg){
			printf("no solution\n");
		}
	}	
}


/*
int main(){

	int n, m, c, k, seg;
	
	cin >> n;
	
	
	while(n--){
	
		cin >> m >> c;
		int dp[m+1];
		fill(dp,dp+m+1,0);
		
		for(int i = 0; i < c; i++){
			cin >> k;
			int wt[k];
			for(int j = 0; j < k; j++){
				cin >> *(wt+j);
			}
			for(int j = m; j >= 0; j--){
				
				seg = 0;
				for(int p = 0; p < k; p++){
					if(wt[p] <= j && dp[j] < wt[p] + dp[j-wt[p]] && (i == 0 || dp[j-wt[p]] != 0)){
						dp[j] = wt[p] + dp[j-wt[p]];
						seg = 1;
					}
				}
				
				if(!seg)
					dp[j] = 0;
			}
		}
		seg = 0;
		for(int i = m; i >= 0; i--){
			if(dp[i] != 0){
				printf("%d\n",dp[i]);
				seg = 1;
				break;
			}
		}
		if(!seg){
			printf("no solution\n");
		}
	}



	return 0;
}
*/
