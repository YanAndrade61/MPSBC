#include <bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[], int n, int c){

	int dp[c+1];
	
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1; i <= n; i++){
		for(int j = c; j >= 0; j--){
			if(wt[i-1] <= j)
				dp[j] = max( dp[j], val[i-1] + dp[j-wt[i-1]]);
		}
	}
	return dp[c];
}

int main(){

	int n,c;
	
	cin >> c >> n;
	int wt[n], val[n];
	
	for(int i = 0; i < n; i++)
		cin >> *(wt+i) >> *(val+i);
	cout << knapsack(wt, val, n, c) << endl;
}
