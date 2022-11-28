#include <bits/stdc++.h>

using namespace std;

int main(){

	long long int N,ground;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> ground;
		
		if(ground%3 != 0)
			cout << "0\n";
		else
			cout << (ground/3) << "\n";
	}
	
	return 0;
}
