#include<bits/stdc++.h>

using namespace std;


int bfs(int p, int n, int idade[], vector<vector<int>> adj){

	queue<int> q;
	int min = INT_MAX;
	
	bool visited[n+1];
	fill(visited,visited+n+1,0);
	
	q.push(p);
	while(!q.empty()){
	
		int node = q.front();
		q.pop();
		if(visited[node])continue;
		
		visited[node] = true;
		
		for(int j = 0; j < (int)adj[node].size(); j++){
			q.push(adj[node][j]);
			if(idade[adj[node][j]] < min)
				min = idade[adj[node][j]];
		}
	}
	
	return min;
}

int main(){

	int n, m, inst;
	int user1, user2;
	int minAge;
	char c;
	while(true){
	
		cin >> n >> m >> inst;
		if(!cin) break;
		
		int idade[n+1];
		vector<vector<int>> adj(n+1);
		
		for(int i = 1; i <= n; i++)
			cin >> *(idade+i);
		
		for(int i = 0; i < m; i++){
			cin >> user1 >> user2;
			adj[user2].push_back(user1);
		}
		
		for(int i = 0; i < inst; i++){
			
			cin >> c;
			if(c == 'P'){
				cin >> user1;
				minAge = bfs(user1, n, idade, adj);
				minAge == INT_MAX ? printf("*\n") : printf("%d\n",minAge);
				
			}else{
				cin >> user1 >> user2;
				
				for(int i = 1; i <= n; i++){
					for(int j = 0; j < (int)adj[i].size(); j++){
						
						if(adj[i][j] == user1)
							adj[i][j] = user2;
						else if(adj[i][j] == user2)
							adj[i][j] = user1;
					}
				}
				swap(adj[user1], adj[user2]);
				
			}		
		}
	}


}
