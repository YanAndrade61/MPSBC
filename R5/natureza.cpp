 #include<bits/stdc++.h>

using namespace std;

int deepSearch(int origem, int n, vector<vector<int>> adj, int vis[]){

	int cont=0;
	queue<int> s;
	
	bool visited[n+1];
	fill(visited,visited+n+1,0);
	
	s.push(origem);
	while(!s.empty()){
	
		int node = s.front();
		s.pop();
		if(visited[node])continue;	
		
		visited[node] = true;
		vis[node] = 1;
		cont++;
		
		for(int j = 0; j < (int)adj[node].size(); j++)
			s.push(adj[node][j]);
	}
	return cont;
	

}


int main(){

	int c,r,maxC,aux;
	string name1,name2;
	
	while(true){
	
		cin >> c >> r;
		if( c == 0 && r == 0)break;
		
		vector<vector<int>> adj(c);
		map<string,int> anim;
		int visited[c];
		maxC = INT_MIN;
		
		for(int i = 0; i < c; i++){
			cin >> name1;
			anim[name1] = i;
			visited[i] = 0;
		}
		
		for(int i = 0; i < r; i++){
		
			cin >> name1 >> name2;
			adj[anim[name1]].push_back(anim[name2]);
			adj[anim[name2]].push_back(anim[name1]);
		}
		
		for(int i = 0; i < c; i++){
		
			if(visited[i] == 0){
				aux = deepSearch(i,c,adj,visited);
			}
			if(aux+1 > maxC)maxC = aux;
		}	
		
		printf("%d\n",maxC);
	}
}
