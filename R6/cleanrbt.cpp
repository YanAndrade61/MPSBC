#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int n, m, newx, newy;

char tab[MAX_N][MAX_N];

 breathSearch(int x, int y){

	queue<pair<int,int>> q;
	vector<vector<int>> dist(n,vector<int>(m,0));
	vector<vector<int>> visited(n,vector<int>(m,0));
	dist[x][y] = 0;

	q.push(make_pair(x,y));
	while(!q.empty()){
	
		pair<int,int> top = q.front();
		q.pop();
		x = top.first;
		y = top.second;
		
		if(x < 0 || x >= n) continue;
		
		if(y < 0 || y >= m) continue;
	
		if(tab[x][y] == 'x') continue;
		
		if(tab[x][y] == '*'){ 
			
			newx = x;
			newy = y;
			return dist[x][y];
		}
		if(visited[x][y] == 1) continue;
		
		visited[x][y] = 1;
		
		if(x-1 >= 0 && visited[x-1][y] != 1){
			q.push(make_pair(x-1, y));
			dist[x-1][y] = dist[x][y] +1;
		}
		if(x+1 < n && visited[x+1][y] != 1){
			q.push(make_pair(x+1, y));
			dist[x+1][y] = dist[x][y] +1;
		}
		if(y-1 >= 0 && visited[x][y-1] != 1){
			q.push(make_pair(x, y-1));
			dist[x][y-1] = dist[x][y] +1;
		}
		if(y+1 < m && visited[x][y+1] != 1){
			q.push(make_pair(x, y+1));
			dist[x][y+1] = dist[x][y] +1;
		}
	}
	
	return -1;
}

int main(){

	int x, y, aux;
	long long int total;
	char c;
	
	while(true){
		cin >> m >> n;
		if(m == 0 && n == 0)break;
		
		total = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> c;
				tab[i][j] = c;
				if(c == 'o'){
					//printf("%d %d\n",i,j);
					x = i;
					y = j;
				}
			}
		}
		
		while(true){
		
			tab[x][y] = '.';
			aux = breathSearch(x,y);
			//printf("%d %d %d %d %d\n",x,y,newx,newy,aux);
			if(aux == -1)break;
			total += aux;
			x = newx;
			y = newy;
		}
		total == 0 ? printf("-1\n") : printf("%lld\n",total);
	}
	return 0;
}

