#include<bits/stdc++.h>

using namespace std;

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
	string amigo, dep;
	
	while(true){
	
		cin >> n;
		if(n == 0)break;
		
		map<string,int> nomesMap;
		vector<string> nomesLst;
		vector<vector<int>> adj(n);
		vector<int> L;
		int raizes[n], visited[n];
		fill(raizes, raizes+n, 1);
		fill(visited, visited+n, 0);
		
		for(int i = 0; i < n; i++){
			cin >> amigo;
			nomesMap[amigo] = i;
			nomesLst.push_back(amigo);
		}
		for(int i = 0; i < n; i++){
			cin >> amigo >> m;
			for(int j = 0; j < m; j++){
				cin >> dep;
				adj[nomesMap[amigo]].push_back(nomesMap[dep]);
				raizes[nomesMap[dep]] = 0;
			}
		}
		
		
		for(int i = 0; i < n; i++){
			if(!raizes[i])continue;
			visita(i, visited, L, adj);
		}
		printf("Teste %d\n", cont++);
		if((int)L.size() < n)
			printf("impossivel\n");
		else
			for(int i = 0; i < (int)L.size(); i++){
				cout << nomesLst[L[i]] << " ";
			}
		printf("\n\n");
	}

}
