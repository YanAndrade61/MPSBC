#include <bits/stdc++.h>

using namespace std;

int tab[10][10];

int breathSearch(int x, int y, int n, int m){

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
	
		if(tab[x][y] == 2) continue;
		
		if(tab[x][y] == 0) return dist[x][y];
	
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

	int n, m, x, y, num;
	
	cin >> n >> m;
		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> num;
			tab[i][j] = num;
			if(num == 3){
				x = i;
				y = j;
			}
		}
	}
	printf("%d\n",breathSearch(x,y,n,m));
	
	return 0;
}
