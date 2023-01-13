#include<bits/stdc++.h>
#define MAX_N 250

using namespace std;

int n, m, c, k;

int adj[MAX_N][MAX_N];

int d[MAX_N];

int dijkstra(int origin, int dest){

	queue<int> fila;
	
	d[origin] = 0;
	fila.push(origin);
	
	while(!fila.empty()){
	
		int i = fila.front();
		fila.pop();
		
		for(int j = 0; j < n; j++){
			if(adj[i][j] != INT_MAX && d[j] > d[i] + adj[i][j]){
				
				d[j] = d[i] + adj[i][j];
				fila.push(j);
			
			}
		}
	}

	return d[dest];

}

int main(){

	int u, v, t;
	
	while(true){
	
		cin >> n >> m >> c >> k;
		if(n == 0 && m == 0 && c == 0 && k == 0)break;
		
		for(int i = 0; i < n; i++){
			d[i] = INT_MAX;
			for(int j = 0; j < n; j++)
				adj[i][j] = INT_MAX;
		}
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> t;
			
			if( (u >= c && v >= c) || (u < c && v < c && abs(u-v) == 1)){
				adj[u][v] = t; 
				adj[v][u] = t;
			}
			if(u < c && v >= c)
				adj[v][u] = t;
			if(u >= c && v < c)
				adj[u][v] = t;		 
		}
		
		printf("%d\n", dijkstra(k, c-1));
		
	}
	
	return 0;
}
