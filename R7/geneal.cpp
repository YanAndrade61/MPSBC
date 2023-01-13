#include<bits/stdc++.h>
#define MAX_N 2000

using namespace std;

int graph[MAX_N][MAX_N];

void floydWarshall(int n){
	
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

	int n, u, v, id=0, imax, jmax, dmax = 0;
	string pai, filho;
	map<string,int> m;
	map<int,string> im;
	
	cin >> n;
	
	for(int i = 0; i < MAX_N; i++){
		for(int j = 0; j < MAX_N; j++){
			graph[i][j] = INT_MAX;
		}
	}
	
	while(n--){
		cin >> pai >> filho;
		
		if(m.find(pai) == m.end()){
			im[id] = pai;
			m[pai] = id++;
		}
		if(m.find(filho) == m.end()){
			im[id] = filho;
			m[filho] = id++;
		}
		
		u = m[pai];
		v = m[filho];
		if(graph[u][v] == INT_MAX){
			graph[u][v] = 1;
			graph[v][u] = 1;	
		}
	}
	
		
	floydWarshall(id);
/*	
	for(int i = 0; i < id; i++){
		for(int j = 0; j < id; j++){
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
*/	
	for(int i = 0; i < id; i++){
		for(int j = 0; j < id; j++){
			if(graph[i][j] != INT_MAX && graph[i][j] > dmax){
				dmax = graph[i][j];
				imax = i;
				jmax = j;
			}
		}
	}
	if(im[imax] > im[jmax])
		cout << im[jmax] << " " << im[imax];
	else
		cout << im[imax] << " " << im[jmax];
	printf(" %d\n\n", dmax);
		
	
}
