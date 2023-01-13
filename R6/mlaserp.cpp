#include<bits/stdc++.h>
#define MAX_N 100
#define MAX_M 100

using namespace std;

typedef pair<int,int> ipair;

int n, m;

char tab[MAX_N][MAX_M];

int mirror[MAX_N][MAX_M];

int visited[MAX_N][MAX_M];

int X[] = {0, 0, 1, -1};

int Y[] = {1, -1, 0, 0};

bool safe(int x, int y){

	if((x < 0 || y < 0) || (x >= n || y >= m ))
		return false;
	if(tab[x][y] == '*')
		return false;
	return true;

}

int bfs(int x, int y){	
	
	int cont=0,xc,yc;
	
	queue<ipair> fila;
	vector<vector<ipair>> whoTo(n,vector<ipair>(m,make_pair(-1,-1)));
	
	fila.push(make_pair(x,y));
	
	while(!fila.empty()){
	
		ipair v = fila.front();
		ipair ant = whoTo[v.first][v.second];
		fila.pop();
		
		if(tab[v.first][v.second] == 'C'){
			xc = v.first;
			yc = v.second;
		}
		
		if(visited[v.first][v.second])continue;
		visited[v.first][v.second] = true;
		
		for(int i = 0; i < 4; i++){
			if(safe(v.first + X[i], v.second + Y[i])){
				
				
				fila.push(make_pair(v.first+X[i], v.second+Y[i]));
				whoTo[v.first + X[i]][v.second + Y[i]] = v;
				
				if(ant != make_pair(-1,-1)){
					if(ant.first != v.first + X[i] && ant.second != v.second + Y[i] && 
					   (mirror[v.first + X[i]][v.second + Y[i]] == 0 ||
					    mirror[v.first + X[i]][v.second + Y[i]] > mirror[v.first][v.second] + 1)){
						mirror[v.first + X[i]][v.second + Y[i]] = mirror[v.first][v.second] + 1;			
					} 		
					else if(mirror[v.first + X[i]][v.second + Y[i]] == 0){
						mirror[v.first + X[i]][v.second + Y[i]] = mirror[v.first][v.second];			
					}
				}
				
			}
		}
	}
	
	return mirror[xc][yc];

}

int main(){
	
	int vx, vy;
	char c;
	cin >> m >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> c;
			tab[i][j] = c;
			if(c == 'C'){
				vx = i;
				vy = j;	
			}
			mirror[i][j] = 0;
			visited[i][j] = 0;
		}
	}	
	tab[vx][vy] = '.';
	printf("%d\n",bfs(vx,vy));
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ",mirror[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}
