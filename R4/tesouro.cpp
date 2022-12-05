#include <bits/stdc++.h>

using namespace std;

int subSetSum(vector<int> t, int n, int sum){

	int m[n+1][sum+1] = {};
	for(int i=0; i<=n; i++)
		m[i][0] = 1;
	
	for(int i=1; i<=sum; i++)
		m[0][1] = 0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			
			if(t[i-1] > j)
				m[i][j] = m[i-1][j];
			else
				m[i][j] = m[i-1][j] || m[i-1][j-t[i-1]];
		}
	}
	return m[n][sum];
}

int main(){
		
	int x, y, n, aux, s1, s2, s,teste=1;
	
	while(true){
	
		cin >> x >> y >> n;
		if(x==0 && y==0 && n==0)break;
		
		vector<int> t;
		s=0;
		
		for(int i=0;i<n;i++){
			cin >> aux;
			t.push_back(aux);
			s += aux;
		}
		if((s+x+y)%2){
			printf("Teste %d\nN\n\n",teste++);
			continue;			
		}
		
		s1 = abs(y-x+s)/2;
		s2 = abs(x-y+s)/2;
		
		if(subSetSum(t,n,s1) || subSetSum(t,n,s2))
			printf("Teste %d\nS\n\n",teste++);
		else
			printf("Teste %d\nN\n\n",teste++);
		
	}
	return 0;
}
