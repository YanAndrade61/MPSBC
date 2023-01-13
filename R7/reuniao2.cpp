#include<bits/stdc++.h>
#define MAX_N 100

using namespace std;

int n, m;
int graph[MAX_N][MAX_N];

void floydWarshall(){
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(graph[i][k] != INT_MAX &&
				   graph[k][j] != INT_MAX &&
				   graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}			
		}	
	}
}

int main(){

	int u, v, w;
		
	cin >> n >> m;
	
	int maxArray[n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = INT_MAX;
		}
	}
	
	while(m--){
		cin >> u >> v >> w;
		if(graph[u][v] == INT_MAX || graph[u][v] > w){
			graph[u][v] = w;
			graph[v][u] = w;	
		}
	}	
	floydWarshall();
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	*/
	for(int i = 0; i < n; i++){
		maxArray[i] = *max_element(begin(graph[i]),end(graph[i]));
	}
	printf("%d\n",*min_element(maxArray,maxArray+n));
		
	
}
