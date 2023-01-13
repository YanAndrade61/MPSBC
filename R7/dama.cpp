#include<bits/stdc++.h>

using namespace std;

int main(){

	int x1, x2, y1, y2, xdif, ydif;

	while(true){
	
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)break;
		
		xdif = x2 - x1;
		ydif = y2 - y1;
		
		if(xdif == 0 && ydif == 0)
			printf("0\n");
		else if(abs(xdif) == abs(ydif) || xdif == 0 || ydif == 0)
			printf("1\n");
		else
			printf("2\n");
	
	
	}
}
