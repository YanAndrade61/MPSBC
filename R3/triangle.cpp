#include <bits/stdc++.h>

using namespace std;

int checkTriangle(int x[],int y[]){

	
	int A = (int)(pow(x[0]-x[1],2)+pow(y[0]-y[1],2));
	int B = (int)(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
	int C = (int)(pow(x[2]-x[0],2)+pow(y[2]-y[0],2));
	
	if((A > 0 && B > 0 && C > 0) && (A == (B+C) || B == (A+C) || C == (A+B)))
		return 1;
	else
		return 0;

}



int main(){

	int x[3],y[3];
	int move[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
	for(int i = 0; i < 3; i++)
		cin >> *(x+i) >> *(y+i);
	
	if(checkTriangle(x,y)){
		cout << "RIGHT\n";
		return 0;
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			x[i] += move[j][0];
			y[i] += move[j][1];
			if(checkTriangle(x,y)){
				cout << "ALMOST\n";
				return 0;
			}
			x[i] -= move[j][0];
			y[i] -= move[j][1];			
		}	
	}
	cout << "NEITHER\n";
	
	return 0;
}
