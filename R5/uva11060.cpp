#include<bits/stdc++.h>

using namespace std;

bool fn(pair<int,int> x, pair<int,int> y){

	if(x.first != y.first)
		return x.first < y.first;
	return x.second < y.second;
	
} 

void visita(int node, int visited[], vector<int>& L, vector<vector<int>> adj){

	if(!visited[node]){
		visited[node] = 1;
		for(int i = 0; i < (int)adj[node].size(); i++){
			visita(adj[node][i], visited, L, adj);
		}
		L.push_back(node);
	}
}


int main(){

	int n, m, cont=1;
	string bebida, dep;
	
	while(true){
	
		cin >> n;
		if(!cin)break;
		
		vector<pair<int,int>> ord;
		map<string,int> nomesMap;
		vector<string> nomesLst;
		vector<vector<int>> adj(n);
		vector<int> L;
		int raizes[n], visited[n];
		
		fill(raizes, raizes+n, 1);
		fill(visited, visited+n, 0);
		
		for(int i = 0; i < n; i++){
			cin >> bebida;
			nomesMap[bebida] = i;
			nomesLst.push_back(bebida);
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> bebida >> dep;
			adj[nomesMap[dep]].push_back(nomesMap[bebida]);
			raizes[nomesMap[bebida]] = 0;
		}
		
		for(int i = 0; i < n; i++){
			ord.push_back(make_pair((int)adj[i].size(),i));
		}
		sort(ord.begin(),ord.end(),fn);
		
		for(int i = 0; i < n; i++){
			printf("%d\n",ord[i].first);
			if(!raizes[ord[i].second])continue;
			visita(ord[i].second, visited, L, adj);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", cont++);
		for(int i = 0; i < (int)L.size(); i++){
			cout << " " << nomesLst[L[i]];
		}
		printf(".\n\n");
	}

}
