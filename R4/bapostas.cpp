#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, max, acc, num;
	
	while(true){
	
		cin >> n;
		if(n == 0)break;
		max =0;
		acc=0;
		while(n--){
		
			cin >> num;
			acc = num+acc >= 0 ? acc + num : 0;
			if(acc > max) max = acc;
		}
		max > 0 ? printf("The maximum winning streak is %d.\n",max) : printf("Losing streak.\n"); 
	}

	return 0;
}
