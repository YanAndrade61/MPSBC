#include<bits/stdc++.h>
#define MAX_N 100

using namespace std;
typedef pair<int,int> ipair;

int n;

int d[MAX_N+1];

int whoTo[MAX_N+1];

void dijkstra(int src, vector<vector<ipair>> adj){

	int v,u,wt;
	priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
	
	for(int i = 0; i <= n; i++)
		d[i] = INT_MAX;
	
	pq.push(make_pair(0,src));
	d[src] = 0;
	
	while(!pq.empty()){
	
		v = pq.top().second;
		pq.pop();
		
		vector<ipair>::iterator it = adj[v].begin();
		for(; it != adj[v].end(); it++){
		
			u = (*it).first;
			wt = (*it).second;	
			if(d[u] > d[v] + wt){
				d[u] = d[v] + wt;
				whoTo[u] = v;
				pq.push(make_pair(d[u], u));
			}
		}
	}
}	


int main(){

	int m, u, v, t, src, end;
	
	while(true){
	
		cin >> n >> m;
		if(n == 0 && m == 0)break;
		
		vector<vector<ipair>> adj(n+1);
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> t;
			adj[u].push_back(make_pair(v,t)); 
		}
		cin >> src >> end;
		
		dijkstra(src, adj);
		
		d[end] == INT_MAX ? printf("-1\n") : printf("%d\n",d[end]);
	}
	


	return 0;
}
