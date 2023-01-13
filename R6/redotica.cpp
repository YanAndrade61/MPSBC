#include<bits/stdc++.h>
#define MAX_N 101
using namespace std;

int n, m;

		
int wt[MAX_N][MAX_N];

int inTree[MAX_N];

int d[MAX_N];

int whoTo[MAX_N];

void initialize(){

	for(int i = 0; i <= n; i++){
		inTree[i] = 0;
		d[i] = INT_MAX;
		for(int j = 0; j <= n; j++)
			wt[i][j] = INT_MAX; 
	}
}

void updateDist(int target){

	for(int i = 1; i <= n; i++)
		if(wt[target][i] != INT_MAX && d[i] > wt[target][i]){
			d[i] = wt[target][i];
			whoTo[i] = target;	
		}
}

int prim(){

	int min,total=0;
	
	/*Insert the first node in tree*/
	inTree[1] = 1;	
	updateDist(1);
	
	
	for(int treeSize = 1; treeSize < n; treeSize++){
		/*Find the node with the smallest dist to the tree*/	
		min = -1;
		for(int i = 1; i <= n; i++){
			if(!inTree[i])
				if(d[i] != INT_MAX && (min == -1 || d[min] > d[i]))
					min = i;
		}
		
		min > whoTo[min] ? printf("%d %d\n",whoTo[min],min) : printf("%d %d\n",min,whoTo[min]);
		
		inTree[min] = 1;
		total += d[min];
		updateDist(min);
	}
	
	return total;
}

int main(){

	int u, v, z, test = 1;
	
	while(true){
		
		cin >> n >> m;
		if(n == 0 && m == 0)break;
		initialize();
		
		for(int i = 0; i < m; i++){
			cin >> u >> v >> z;
			wt[u][v] = z;
			wt[v][u] = z;
		}
		
		printf("Teste %d\n",test++);
		prim();
		printf("\n");
	
	}

}


