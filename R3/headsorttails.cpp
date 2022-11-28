#include <bits/stdc++.h>

using namespace std;

int main(){

	int x,y,a,b;
	vector<pair<int,int>> resultados;
	cin >> x >> y >> a >> b;
	
	for(int i=a; i<=x ; i++){
		for(int j=b; j<i && j<=y; j++){
			resultados.push_back(make_pair(i,j));
		} 
	}
	
	cout << resultados.size() << "\n";
	for(int i=0; i< (int)resultados.size() ; i++){
		cout << resultados[i].first << " " << resultados[i].second << "\n"; 
	}
	
	return 0;
}
