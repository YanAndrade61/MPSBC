#include<bits/stdc++.h>

#define MAX_N 1010

using namespace std;

int n, m, s, t, b;

int graph[MAX_N][MAX_N];

int d[MAX_N];

void initialize(){

	for(int i = 0; i <= n+1; i++){
		d[i] = INT_MAX;
		for(int j = 0; j <= n+1; j++)
			graph[i][j] = INT_MAX; 
	}
}


int dijkstra(int origin, int dest){

	queue<int> fila;
	
	d[origin] = 0;
	fila.push(origin);
	
	while(!fila.empty()){
	
		int i = fila.front();
		fila.pop();
		
		for(int j = 0; j <= n+1; j++){
			if(graph[i][j] != INT_MAX && d[j] > d[i] + graph[i][j]){
				d[j] = d[i] + graph[i][j];
				fila.push(j);
			}
		}
	}
	return d[dest];
}

int main(){

	cin >> n >> m;
	
	initialize();
	
	for(int i =0; i < m; i++){
		
		cin >> s >> t >> b;
		graph[s][t] = b;
		graph[t][s] = b;	
	} 
	
	printf("%d\n",dijkstra(0,n+1));

}
