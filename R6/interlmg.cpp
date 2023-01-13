#include<bits/stdc++.h>
#define MAX_N 1000
using namespace std;

int n;
		
double wt[MAX_N][MAX_N];

int inTree[MAX_N];

double d[MAX_N];

int whoTo[MAX_N];

double distEucledian(double x1, double y1, double x2, double y2){

	return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void initialize(){

	for(int i = 0; i < n; i++){
		inTree[i] = 0;
		d[i] = FLT_MAX;
		for(int j = 0; j < n; j++)
			wt[i][j] = FLT_MAX; 
	}
}

void updateDist(int target){

	for(int i = 0; i < n; i++)
		if(wt[target][i] != FLT_MAX && d[i] > wt[target][i]){
			d[i] = wt[target][i];
			whoTo[i] = target;	
		}
}

double prim(){

	int min,total=0;
	double max = 0;
	
	/*Insert the first node in tree*/
	inTree[1] = 1;	
	updateDist(1);
	
	
	for(int treeSize = 1; treeSize < n; treeSize++){
		/*Find the node with the smallest dist to the tree*/	
		min = -1;
		for(int i = 0; i < n; i++){
			if(!inTree[i])
				if(d[i] != FLT_MAX && (min == -1 || d[min] > d[i]))
					min = i;
		}
		
		if(d[min] > max)
			max = d[min];
		
		inTree[min] = 1;
		total += d[min];
		updateDist(min);
	}
	
	return max;
}

int main(){

	int test=1;
	double x,y;
	
	while(true){
		
		cin >> n;
		if(n == 0)break;
		
		initialize();
		
		vector<pair<double,double>> coord;
		
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			coord.push_back(make_pair(x,y));
		}
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				wt[i][j] = distEucledian(coord[i].first, coord[i].second, coord[j].first, coord[j].second);
				wt[j][i] = wt[i][j];
			}
		}
		
		printf("%.4lf\n",test++,prim());
	
	}

}


