#include <bits/stdc++.h>

using namespace std;

int main(){

	int teste=1, n, max;
	
	while(true){
	
		vector<int> arr;
		vector<int> seq;
		max=0;
		while(true){
			cin >> n;
			if(n == -1)break;
			arr.push_back(n);
			seq.push_back(1);
		}
		if((int)arr.size() <= 0)break;
		
		for(int i = 1; i < (int)arr.size(); i++){
			for(int j=0; j < i; j++){
				if(arr[i] < arr[j])
					seq[i] = seq[j]+1;
				if(seq[i]>max)
					max = seq[i];
			}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",teste++,max);
	}


	return 0;
}
