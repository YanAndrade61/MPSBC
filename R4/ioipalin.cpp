#include<bits/stdc++.h>

using namespace std;

int lcs(string str1, string str2, int n1, int n2){

	int dp[n1+1][n2+1];
	
	for(int i=0; i <= n1; i++){
	
		for(int j=0; j <= n2; j++){
		
			if(i == 0 || j ==0)
				dp[i][j] = 0;
			else if(str1[i-1] == str2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[n1][n2];
}

int main(){

	int n;
	string str, rev;
	
	cin >> n >> str;
	
	rev = string(str.rbegin(), str.rend());
	
	cout << n - lcsReverse(str,rev,n,n) << endl;
	return 0;
}	
