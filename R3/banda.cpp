#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100

int main(){

	int n,m,x,y,z,max=0;
	int m1=1,m2=2,m3=3;
	int mus[MAX_N][MAX_N] = {0};
	
	cin >> n >> m;
	
	for(int i=0; i < m; i++){
		cin >> x >> y >> z;
		mus[x][y] = z;
		mus[y][x] = z;
	}
	
	for(int i=1; i < n+1; i++){
		for(int j = i+1; j < n+1; j++){
			for(int k = j+1; k < n+1; k++){
				if(mus[i][j] + mus[j][k] + mus[i][k] > max){
					max = mus[i][j] + mus[j][k] + mus[i][k];
					m1 = i;
					m2 = j;
					m3 = k;
				}
			}
		}
	}
	printf("%d %d %d\n",m1,m2,m3);

	return 0;
}
