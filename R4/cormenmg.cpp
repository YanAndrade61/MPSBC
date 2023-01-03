#include<bits/stdc++.h>

using namespace std;

bool fn(pair<int,int> x, pair<int,int> y){

	return x.second < y.second;
}

int busca(int pref[], int L, int R, int val){

	int mid = (L+R)/2;

	if(val == pref[mid])
		return mid;
	if(L > R)
		return -1;
	if(val > pref[mid])
		return busca(pref, mid+1, R, val);
	else
		return busca(pref, L, mid-1, val);
}


int main(){

	int s, n, auxInt, adams = 42;
	
	cin >> s;
	
	while(s--){
		
		cin >> n;
		
		int pref[n], cont=0;
		vector<pair<int,int>> tab;
		pair<int,int> auxPair(-1,-1);
		
		cin >> *(pref);
		for(int i = 1; i < n; i++){
			cin >> auxInt;
			pref[i] = pref[i-1] + auxInt;
		}
		
		for(int i = 0; i < n; i++){
			if(pref[i] == adams){
				tab.push_back(make_pair(0,i));
			}else if(pref[i] > adams){
				auxInt = pref[i] - adams;
				
				auxInt = busca(pref,0,n-1,auxInt);
				if(auxInt != -1)
					tab.push_back(make_pair(auxInt+1,i));
			}
		}
		
		sort(tab.begin(),tab.end(),fn);
		for(int i = 0; i < (int)tab.size(); i++){
			if(tab[i].first > auxPair.second){
				auxPair = tab[i];
				cont++;
			}
		}		
		printf("%d\n",cont);
	
	}

	return 0;

}
