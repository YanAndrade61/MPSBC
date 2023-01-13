#include<bits/stdc++.h>
#define MAX_N 101

using namespace std;

int n, m, c;

int adj[MAX_N][MAX_N];
int stop[MAX_N];
int d[MAX_N];

int dijkstra(int origin, int dest){

	queue<int> fila;
	
	d[origin] = 0;
	fila.push(origin);
	
	while(!fila.empty()){
	
		int i = fila.front();
		fila.pop();
		
		for(int j = 1; j <= n; j++){
			if(stop[j] == 1){
				//printf("%d %d %d \n",i,j,d[i] + adj[i][j]);
				if(adj[i][j] != INT_MAX && d[j] > d[i] + adj[i][j]){
					d[j] = d[i] + adj[i][j];
					fila.push(j);
				}
			}
		}
	}
	if(d[dest] == INT_MAX) return -1;
	else return d[dest];
}

int main(){

	int u, v, w, src, dest, t, test = 1;
	
	while(true){
	
		cin >> n >> m;
		if(!cin)break;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				adj[i][j] = INT_MAX;
		}
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> w;
			if(adj[u][v] > w)
				adj[u][v] = w;
			//adj[v][u] = w;		 
		}
		
		printf("Instancia %d\n",test++);
		cin >> c;
		
		for(int i = 0; i < c; i++){
		
			cin >> src >> dest >> t;
			for(int j = 1; j <= n; j++){
				if(j <= t)stop[j] = 1;
				else stop[j] = 0;
				d[j] = INT_MAX;
			}
			stop[src] = 1;
			stop[dest] = 1;
			
			printf("%d\n",dijkstra(src,dest));
		}
		printf("\n");
	}
	
	return 0;
}
