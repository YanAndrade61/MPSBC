#include<bits/stdc++.h>

using namespace std;

bool match(char c1, char c2){

	if((c1 == 'C' && c2 == 'F') || (c1 == 'F' && c2 == 'C'))
		return true;

	if((c1 == 'B' && c2 == 'S') || (c1 == 'S' && c2 == 'B'))
		return true;
	
	return false;
}

int main(){

	int cont;
	string fita;
	
	while(true){
		
		cin >> fita;
		if(!cin)break;
		
		stack<char> stk1;
		stack<char> stk2;
		cont = 0;
		
		for(int i = 0; i < (int)fita.length(); i++){
			//printf("%c\n",fita[i]);
			stk1.push(fita[i]);
		}
		while(!stk1.empty()){
			
			
			char c = stk1.top();
			stk1.pop();
			if(!stk2.empty() && match(c, stk2.top())){
				cont++;
				stk2.pop();
			}
			else
				stk2.push(c);
		}
		printf("%d\n",cont);
	}
		

	return 0;
}
