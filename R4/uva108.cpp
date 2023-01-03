#include <bits/stdc++.h>

using namespace std;


int main(){

	int n, num, maxSum = INT_MIN;
	
	cin >> n;
	
	int tab[n][n];
	int temp[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> num;
			tab[i][j] = num;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int p = i; p < n; p++){
				for(int q = j; q < n; q++){
					temp[p][q] = tab[p][q];
					printf("%d %d %d\n",p,q,temp[p][q]);
										
					if(p-1 >= i)
						temp[p][q] += temp[p-1][q];
					if(q-1 >= j)
						temp[p][q] += temp[p][q-1];
					if(q-1 >= j && p-1 >= i)
						temp[p][q] -= temp[p-1][q-1];
					if(temp[p][q] > maxSum)
						maxSum = temp[p][q];
				}
			}
		
		}
	}
	
	printf("%d\n",maxSum);
	
	return 0;
}
