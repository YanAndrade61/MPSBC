include<bits/stdc++.h>
 
using namespace std;
 
int deepSearch(int origem, int n, vector<vector<int>> adj){
 
	int cont=0;
	stack<int> s;
	bool visited[n+1];
	fill(visited,visited+n+1,0);
	
	s.push(origem);
	while(!s.empty()){
	
		int node = s.top();
		s.pop();
		if(visited[node])continue;
		
		visited[node] = true;
		cont++;
		
		for(int j = 0; j < (int)adj[node].size(); j++)
			s.push(adj[node][j]);
	}
	return cont;
	
 
}
 
int main(){
 
	int n,m, v, w, cont =1;
	
	while(true){
	
		cin >> n >> m;
		if(n == 0)break;	
		
		vector<vector<int>> adj(n+1);
		
		for(int i = 0; i < m; i++){
			cin >> v >> w;
			adj[v].push_back(w);
			adj[w].push_back(v);			 
		}
		
		printf("Teste %d\n", cont++);
		
		deepSearch(1,n,adj) == n ? printf("normal\n\n") : printf("falha\n\n");
		
	}
 
} 
