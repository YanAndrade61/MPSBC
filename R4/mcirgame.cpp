#include<bits/stdc++.h>

using namespace std;

int char2int(char c){
	return c-'0';
}
int int2char(char c){
	return c+'0';
}

string sum(string a, string b){
    int t = 0, s, i, j;
    int n = a.length(), m = b.length();
    if(m > n)
        a.insert(0, m - n, '0');
    n = a.length();
    for (i = n-1, j = m-1; i >= 0;i--,j--){
        if(j >= 0)
            s = (char2int(a[i]) + char2int(b[j])) + t;
        else
            s = char2int(a[i]) + t;
        t = s / 10;
        a[i] = int2char(s % 10);
    }
    if(t)
        a.insert(0,1,int2char(t));
    return a;
}
 

string mult(string a, string b){

    int n = a.length(), m = b.length();
    
    vector<int> v(n + m, 0);
    for (int i = n-1; i >= 0;i--)
        for (int j = m-1; j >= 0;j--){
        	v[i + j] += (char2int(a[i]) * char2int(b[j]));
	//	printf("%d %d\n",char2int(a[i]),char2int(b[j]));
        }
        
    n += m;
    a.resize(v.size());
    for (int s, i = n-2, t = 0; i >= 0; i--)
    {
        s = t + v[i];
        //cout << v[i] << endl;
        v[i] = s % 10;
        t = s / 10;
        a[i] = int2char(v[i]);
    }
/*  
    for (int i = n - 1; i >= 1 && !v[i];i--)
            a.pop_back();
  */  
    return a;
}

string mcirgame(int n, string dp[]){
	
	for(int i=2; i <= n; i++){
		if(dp[i] != "0") continue;
		for(int j=0; j < i; j++){
			dp[i] = sum(dp[i], mult(dp[j],dp[i-j-1]));
			cout << dp[i];
		}
	}	
	return dp[n];
}

int main(){

	int n;
	string dp[151], zero = "0";
	fill(dp,dp+151,"0");
	dp[0] = dp[1] = "1";
	//string a = "0";
	//string b = "0";
	//cout << sum(a,b) << endl;
	while(true){
		cin >> n;
		if(n == -1)break;
		cout << mcirgame(n,dp) << endl;
		
	}
	
	return 0;		
}




