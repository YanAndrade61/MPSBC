#include<bits/stdc++.h>
 
using namespace std;
 
int breathSearch(int origem, int n, vector<vector<int>> adj, vector<int>& v, int p){
 
	int cont=0;
	queue<int> s;
	int visited[n+1];
	int dist[n+1];
	
	fill(visited,visited+n+1,0);
	fill(dist,dist+n+1,0);
	
	s.push(origem);
	dist[origem] = p+1;
	while(!s.empty()){
	
		int node = s.front();
		s.pop();
		
		if(visited[node])continue;
		if(dist[node] <= p)v.push_back(node);
		visited[node] = true;
		
		
		dist[origem]=0;
		for(int j = 0; j < (int)adj[node].size(); j++){
			s.push(adj[node][j]);
			if(dist[adj[node][j]] == 0)
				dist[adj[node][j]] = dist[node]+1;
		}
	}
	return cont;
 
}
 
int main(){
 
	int c,e, l, p, x, y, cont =1;
	
	while(true){
	
		cin >> c >> e >> l >> p;
		if(c == 0 && e == 0 && l == 0 && p == 0)break;	
		
		vector<vector<int>> adj(c+1);
		vector<int> v;
		
		for(int i = 0; i < e; i++){
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);			 
		}
		/*
		for(int i = 1; i <= c; i++){
			set<int> s(adj[i].begin(),adj[i].end());
			vector<int> aux(s.begin(),s.end());
			adj[i] = aux;
		
		}
		*/
		printf("Teste %d\n", cont++);

		
		
		deepSearch(l,c,adj,v,p);
		sort(v.begin(),v.end());

		for(int i = 0; i < (int)v.size(); i++)
			printf("%d ",v[i]);
		printf("\n\n");
	}
 
} 
