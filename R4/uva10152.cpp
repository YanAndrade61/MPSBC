#include <bits/stdc++.h>

using namespace std;

int main(){

	int k, n, seq;
	string aux;

    	cin >> k;
	while(k--){
        
		cin >> n;
		map<string,int> dict;
		vector<string> str;
		seq=0;
		getline(cin,aux);
		
		for(int i = 0; i < n ; i++){
		    	getline(cin,aux);
			dict[aux] = i;
		}
		for(int i = 0; i < n ; i++){
		    	getline(cin,aux);
		    	str.push_back(aux);
		}
		
		for(int i = n-1; i >= 1; i--){
			if(seq == 0 && dict[str[i]] < dict[str[i-1]])
				seq = 1;
			if(seq==1)
				cout << str[i-1] << "\n";  	
		
		}
		
		cout << "\n";
	}	

}
