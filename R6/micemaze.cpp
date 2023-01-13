#include<bits/stdc++.h>
#define MAX_N 101

using namespace std;

int n;

int adj[MAX_N][MAX_N];
int d[MAX_N];

int dijkstra(int origin, int dest){

	queue<int> fila;
	
	for(int i = 0; i <= n; i++)
		d[i] = INT_MAX;
		
	d[origin] = 0;
	fila.push(origin);
	
	while(!fila.empty()){
	
		int i = fila.front();
		fila.pop();
		
		for(int j = 1; j <= n; j++){
			//printf("%d %d %d %d\n",i,j,d[i] + adj[i][j],d[j]);
			if(adj[i][j] != INT_MAX && d[j] > d[i] + adj[i][j]){
				d[j] = d[i] + adj[i][j];
				fila.push(j);
			}
		}
	}
	//printf("%d %d\n",origin,d[dest]);
	return d[dest];
}

int main(){

	int u, v, w, e, t, m, cont=0;
	
	while(true){
	
		cin >> n >> e >> t >> m;
		if(!cin)break;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				adj[i][j] = INT_MAX;
		}
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> w;
			adj[u][v] = w;		 
		}
		
		for(int i = 1; i <= n; i++){
			if(dijkstra(i,e) <= t)cont++;
		}
		printf("%d\n",cont);
	}
	
	return 0;
}
