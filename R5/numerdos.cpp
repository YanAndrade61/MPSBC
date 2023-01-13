#include<bits/stdc++.h>

using namespace std;

int breathSearch(int origem, int n, vector<vector<int>> adj, int dist[]){
 
	int cont=0;
	queue<int> s;
	int visited[n+1];
	
	fill(visited,visited+n+1,0);
	
	s.push(origem);
	while(!s.empty()){
	
		int node = s.front();
		s.pop();
		
		if(visited[node])continue;
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
	
	int a, id, n, erdos, cont = 1;
	string name, line;
		
	while(true){
	
		cin >> a;
		if(a == 0)break;
		
		map<pair<string,string>,int> autores;
		vector<vector<int>> artigos;
		id = 0;
		erdos = -1;
		
		getline(cin,line);
		for(int i = 0; i < a; i++){
			getline(cin,line);
			stringstream ss(line);
			vector<int> artigo;
			
			while(!ss.eof()){
				getline(ss,name,',');
				if(name[0] == ' ')
					name = string(name.begin()+1,name.end());
				if(name[name.length()-1] == '.')
					name = string(name.begin(),name.end()-1);
				
				pair<string,string> autor = make_pair(string(name.begin()+3,name.end()),string(name.begin(),name.begin()+3));
				
				if(autores.find(autor) == autores.end()){
					autores[autor] = id;
					//cout << name+" " << autor[name] << endl; 
					if(name == "P. Erdos")
						erdos = id;
					id++;
				}
				artigo.push_back(autores[autor]);
			}
			artigos.push_back(artigo);	
		}
		n = (int)autores.size();
		vector<vector<int>> adj(n);
		int dist[n];
		fill(dist,dist+n,0);
		
		for(int i = 0; i < a; i++){
			for(int j = 0; j < (int)artigos[i].size(); j++){
				for(int k = j+1; k < (int)artigos[i].size(); k++){
					adj[artigos[i][j]].push_back(artigos[i][k]);
					adj[artigos[i][k]].push_back(artigos[i][j]);
				}
			}
		}
		/*
		for(int i = 0; i < n; i++){
			for(int j = 0; j < (int)adj[i].size(); j++){
				printf("%d ",adj[i][j]);
			}
			printf("\n");	
		}
		*/
		if(erdos != -1)
			breathSearch(erdos,n,adj,dist);

		map<pair<string,string>,int>::iterator it = autores.begin();
		
		printf("Teste %d\n", cont++);
		while(it != autores.end()){
			if(it->second != erdos){
				cout << it->first.second << it->first.first + ": ";
				dist[it->second] == 0 ? printf("infinito\n") : printf("%d\n", dist[it->second]);
			}
			it++;
		}
		printf("\n");
	}
	
}
