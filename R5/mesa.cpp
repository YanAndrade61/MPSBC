#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n,m, v, w, cont =1,connect;
	
	while(true){
		
		cin >> n >> m;
		if(!cin)break;	
		
		vector<vector<int>> matAdj(n+1,vector<int>(n+1,0));
		vector<vector<int>> lstAdj(n+1);
		connect = 1;
		
		for(int i = 0; i < m; i++){
			cin >> v >> w;
			matAdj[v][w] = 1;
			matAdj[w][v] = 1;
			lstAdj[v].push_back(w);
			lstAdj[w].push_back(v);			 
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < (int)lstAdj[i].size(); j++){
				for(int k = j+1; k < (int)lstAdj[i].size(); k++){
					if(matAdj[lstAdj[i][j]][lstAdj[i][k]]){
						connect = 0;
						continue;
					}				
				}	
			}
		}
		
		printf("Instancia %d\n", cont++);
		
		connect ? printf("sim\n\n") : printf("nao\n\n");
		
	}

}
