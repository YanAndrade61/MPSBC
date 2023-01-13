#include<bits/stdc++.h>
#define MAX 5001
using namespace std;

int pd[MAX];

int main(){

	int n, calc=2;
	
 	fill(pd,pd+MAX,-1);
 	pd[0] = 0;
 	pd[1] = 1;
 	
	while(true){
	
		cin >> n;
		if(!cin)break;
		
		printf("The fibonacci number for %d is ",n);
		if(n < calc){
			printf("%d\n",pd[n]);
		}	
		else{
			for(int i = calc; i <= n; i++){
				pd[i] = pd[i-1] +pd[i-2];	
			}
			printf("%d\n",pd[n]);
			calc = n+1;		
		}
	}
	
	
}
