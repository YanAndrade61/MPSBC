#include<bits/stdc++.h>

using namespace std;

int main(){

	int n, tankh, tankah, achouh, achouah;
	
	while(true){
	
		cin >> n;
		if(n == 0)break;
		
		int posto[n];
		int dist[n];
		
		for(int i = 0; i < n; i++)
			cin >> *(posto+i);
	
		for(int i = 0; i < n; i++)
			cin >> *(dist+i);
		
		achouh = -1;
		achouah = -1;
		for(int i = 0; i < n && (achouh == -1 || achouah == -1); i++){
			int jh = i;
			int jah = i;
			tankh = 0;
			tankah = 0;
			while(achouh == -1){
			
				tankh += posto[jh]-dist[jh];
				jh = (jh+1)%n;
				//printf("%d %d %d\n", i, j, tank);
				if(tankh < 0)break;
				if(jh == i){
					achouh = jh;
					break;
				}
			}
			while(achouah == -1){
			
				if(jah - 1 < 0)
					tankah += posto[jah]-dist[n-1];
				else
					tankah += posto[jah]-dist[jah-1];
				
				jah = (jah-1);
				if(jah < 0)jah = n-1;
				//printf("%d %d %d\n", i, j, tank);
				if(tankah < 0)break;
				if(jah == i){
					achouah = jah;
					break;
				}
			}
		}
		printf("%d %d\n",achouh+1, achouah+1);			
	}

	return 0;
}
