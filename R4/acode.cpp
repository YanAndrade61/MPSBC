#include<bits/stdc++.h>

using namespace std;

int main(){

	string str;
	int L, n1, n2;
	int pd[5001];
	
	while(true){
	
		cin >> str;
		if(str == "0")break;
		L = str.length();
		
		pd[0] = pd[1] = 1;
		
		for(int i = 2; i <= L; i++){
			
			pd[i] = 0;
			n1 = str[i-2] - '0';
			n2 = str[i-1] - '0';
			if(n1 == 1 ||( n1 == 2 && n2 <= 6)) 
				pd[i] += pd[i-2];
			if(n2 != 0)
				pd[i] += pd[i-1];
		}
		
		printf("%d\n",pd[L]);
	}

	return 0;
}

