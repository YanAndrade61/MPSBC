#include <bits/stdc++.h>

using namespace std;
/*
void passo( int hx, int hy, int i, int j, int d, int acc){

	
	if(i >= n || i < 0 || j >= n || j < 0)
		return;
	if(acc >= d){
		mapa[i*n+j] += 1;
		if(mapa[i*n+j] > max1){
			max1 = mapa[i*n+j];
			ti = i;
			tj = j; 
		}
		else if(mapa[i*n+j] > max2){
			max2 = mapa[i*n+j];
		}
		return;
	}
	
	for(int k=0; k < 4; k++){
		if(i+passy[k] == hx && j+passx[k] == hy)
			continue;
		passo(i,j,i+passy[k],j+passx[k],d,acc+1);
	}
	
}
*/
int main(){

	int k, x, y, d,n,ti,tj;
	int max1=0,max2=-1;
	cin >> n >> k;
	int mapa[n*n] = {0};
	vector<tuple<int,int,int>> pistas;
	for(int i = 0; i < k; i++){
		cin >> x >> y >> d;
		pistas.push_back(make_tuple(x,y,d));
	}
	for(int i = 0; i < n; i++){
		for(int j=0; j < n; j++){
			for(int a = 0; a< k; a++){
				if(abs(i-get<0>(pistas[a])) + abs(j-get<1>(pistas[a])) == get<2>(pistas[a])){
					mapa[i*n+j] += 1;
					if(mapa[i*n+j] > max1){
						max1 = mapa[i*n+j];
						ti = i;
						tj = j; 
					}
					else if(mapa[i*n+j] > max2){
						max2 = mapa[i*n+j];
					}			
				}
			}
		}
	}
	
	if(max1 == max2)
		printf("-1 -1\n");
	else
		printf("%d %d\n",ti,tj); 	
	
	return 0;
}
