#include<bits/stdc++.h>
#define MAX_N 100

using namespace std;
typedef pair<int,int> ipair;

int n;

vector<vector<int>> adj;

int d[MAX_N];

int whoTo[MAX_N];

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
