#include<bits/stdc++.h>
#define MAX_N 100

using namespace std;
typedef pair<int,int> ipair;

int n;

long long int d[MAX_N];

int whoTo[MAX_N];

void dijkstra(int src, vector<vector<ipair>> adj){

	int v,u,wt;
	priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
	
	for(int i = 0; i < n; i++)
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

	int m, u, v, t, c, src;
	
	while(true){
	
		cin >> n >> m >> c >> src;
		if(n == 0 && m == 0 && c == 0 && src == 0)break;
		
		vector<vector<ipair>> adj(n);
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> t;
			
			if( (u >= c && v >= c) || (u < c && v < c && abs(u-v) == 1)){
				adj[u].push_back(make_pair(v,t)); 
				adj[v].push_back(make_pair(u,t));
			}
			if(u < c && v >= c)
				adj[v].push_back(make_pair(u,t));
			if(u >= c && v < c)
				adj[u].push_back(make_pair(v,t)); 
		 
		}
		
		dijkstra(src, adj);
		
		printf("%lld\n",d[c-1]);
		
	}
	
	return 0;
}
