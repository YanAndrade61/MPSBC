#include<bits/stdc++.h>

using namespace std;

int bfs(int p, int n, int k, set<pair<int,int>>& L, vector<vector<int>> adj){

	queue<int> q;
	int cont = 0;	
	bool visited[n+1];
	int dist[n+1];
	
	fill(visited,visited+n+1,0);
	
	q.push(p);
	dist[p] = 0;
	while(!q.empty()){
	
		int node = q.front();
		q.pop();
		if(visited[node])continue;
		
		visited[node] = true;
		
		
		for(int j = 0; j < (int)adj[node].size(); j++){
			q.push(adj[node][j]);
			dist[adj[node][j]] = dist[node] + 1;
			if(dist[adj[node][j]] == k){
				if(adj[node][j] > node)
					L.insert(make_pair(adj[node][j],node));
				else
					L.insert(make_pair(node,adj[node][j]));
			}
		}
	}
	
	return cont;
}

int main(){
	
	int n, k;
	int v1, v2;
	set<pair<int,int>> L;
	
	cin >> n >> k;
	
	vector<vector<int>> adj(n+1);
		
	for(int i = 0; i < n-1; i++){
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}

	for(int i = 1; i <= n; i++){
		bfs(i,n,k,L,adj);
	}
	
	printf("%d\n",(int)L.size());
}
