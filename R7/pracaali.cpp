#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, imax, praca, e, x, doubt, dif, aux;
	string h;
	char c;
	
	
	while(true){
	
		cin >> n;
		if(n == 0)break;
	
		vector<pair<string,char>> card;
		imax = 0;
		praca = 0;
		e = 0;
		x = 0;
		doubt = 0;
		
		for(int i = 0; i < n; i++){
			cin >> h >> c;
			card.push_back(make_pair(h,c));
			if(c == 'E')e++;
			if(c == 'X')x++;
			if(c == '?')doubt++;
		}
		
		sort(card.begin(),card.end());
		dif = e-x;
		aux = (doubt + (x - e))/2;
		
		for(int i = 0; i < n; i++){
			//printf("%d %d %d %d\n",praca, aux, (int)ceil(doubt/2.0) - dif,doubt/2);
			if(card[i].second == '?'){
				if(aux > 0)
					praca++;
				else
					praca--;
				aux--;	
			}else if(card[i].second == 'E'){
				praca++;
			}
			else if (card[i].second == 'X'){
				praca--;
			}
			if(praca > imax)
				imax = praca;
		}
		printf("%d\n",imax);
	}


	return 0;
}
