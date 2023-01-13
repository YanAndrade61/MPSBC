#include<bits/stdc++.h>

using namespace std;

int breathSearch(int origem, int n, vector<vector<int>> adj, vector<int> folhas){
 
	//int cont=0;
	queue<int> s;
	int visited[n+1];
	int dist[n+1];
	vector<int> distF;   
	fill(dist,dist+n+1,0);
	
	fill(visited,visited+n+1,0);
	
	s.push(origem);
	while(!s.empty()){
	
		int node = s.front();
		s.pop();
		
		if(visited[node])continue;
		visited[node] = true;
		
		dist[origem]=0;

		if(find(folhas.begin(), folhas.end(), node) != folhas.end())
			distF.push_back(dist[node]);

		for(int j = 0; j < (int)adj[node].size(); j++){
			s.push(adj[node][j]);
			if(dist[adj[node][j]] == 0)
				dist[adj[node][j]] = dist[node]+1;
		}
	}
	
	return *max_element(distF.begin(),distF.end());
}

int main(){

	int n, x, y,posto,cont=1;
	int min,aux;	
	
	while(true){
	
		cin >> n;
		if(n == 0)break;
		min = INT_MAX;
		vector<vector<int>> adj(n+1);
		vector<int> folhas;
		
		for(int i = 0; i < n-1; i++){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i = 1; i <= n; i++){
			if((int)adj[i].size() <= 1)
				folhas.push_back(i);
		}
		/*
		for(int i = 0; i < (int)folhas.size(); i++)
			printf("%d ",folhas[i]);
		printf("\n");
		*/
		for(int i = 1; i <= n; i++){
		
			aux = breathSearch(i, n, adj, folhas);	
		//	printf("%d %d\n",i,aux);
			if(min > aux){
				min = aux;
				posto = i;
			}
		}
		printf("Teste %d\n%d\n\n",cont++,posto);
	}
	
	return 0;
}
