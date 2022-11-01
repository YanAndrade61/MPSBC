#include <bits/stdc++.h>

using namespace std;
int base36toDec(char c);
char dectoBase36(int n);

int main(){

    string num[2];
    vector<char> res;
    long int sum;
    int resto;

    while(true){

        cin >> num[0] >> num[1];
        if(num[0] == "0" && num[1] == "0")break;

        sum = 0;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < (int)num[i].length(); j++){
                sum += (base36toDec(num[i][j])*pow(36,num[i].length()-j-1));
            }
        }
        while(sum > 0){
            resto = sum % 36;
            sum = (int)(sum/36);
            res.push_back(dectoBase36(resto));
        }
        reverse(res.begin(),res.end());
        
        for(char c : res){
            cout << c;
        }

        cout << "\n";
        res.clear();
    }

    return 0;
}

char dectoBase36(int n){

    if(n < 10)
        return (char)(n + '0');
    else
        return (char)(n + 'A' - 10);
}

int base36toDec(char c){
    
    if(isdigit(c))
        return (c - 48);
    else
        return (c - 65 + 10);
}
