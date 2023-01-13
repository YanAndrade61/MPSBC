#include<bits/stdc++.h>
#define MAX_N 100
using namespace std;



int n;

int wt[MAX_N][MAX_N];

int inTree[MAX_N];

int d[MAX_N];

int whoTo[MAX_N];


void updateDist(int target){

	for(int i = 0; i < n; i++)
		if(wt[target][i] != 0 && d[i] > wt[target][i]){
			d[i] = wt[target][i];
			whoTo[i] = target;	
		}
}

int prim(){

	int min,total=0;
	
	/*Initialize vectors*/
	for(int i = 0; i < n; i++){
		inTree[i] = 0;
		d[i] = INT_MAX;
	}
	
	/*Insert the first node in tree*/
	inTree[0] = 1;	
	updateDist(0);
	
	
	for(int treeSize = 1; treeSize < n; treeSize++){
		/*Find the node with the smallest dist to the tree*/	
		min = -1;
		for(int i = 0; i < n; i++){
			if(!inTree[i])
				if(d[i] != 0 && (min == -1 || d[min] > d[i]))
					min = i;
		}
		inTree[min] = 1;
		total += d[min];
		updateDist(min);
	}
	
	return total;
}
