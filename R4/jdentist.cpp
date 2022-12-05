#include <bits/stdc++.h>

using namespace std;

bool fn(pair<int,int> x, pair<int,int> y){
	return x.second < y.second;
}

int main(){

	int n, cont=0, h1, h2;
	pair<int,int> aux = make_pair(0,0);
	vector<pair<int,int>> h;
	
	cin >> n;
	
	for(int i =0; i<n; i++){
		cin >> h1 >> h2;
		h.push_back(make_pair(h1,h2));
	}
	sort(h.begin(), h.end(), fn);
	for(int i = 0; i<n; i++){
		if(h[i].first >= aux.second){
			aux = h[i];
			cont++;
		}					
	}
	
	printf("%d\n",cont);
	return 0;
}
