#include <bits/stdc++.h>
#define G 10.0

using namespace std;


double degree2rad(double x){
    return x*3.14159/180;;
}
double calcPoints(int v0, int k1, int k2,double angle){

    double x = v0*v0*sin(2*angle)/G;
    double y = v0*v0*sin(angle)/2*G;
    cout << x << " " << y << "\n";
    return k1*x + k2*y;
}

double buscaBinaria(double ini, double end,int v0, int k1, int k2){

    double mid = (ini+end)/2;
    double e = pow(10,-9);
    if(abs(end-ini) < e)
        return mid;
    if(calcPoints(v0,k1,k2,degree2rad(ini)) > calcPoints(v0,k1,k2,degree2rad(end))) 
        return buscaBinaria(ini,mid,v0,k1,k2);
    else
        return buscaBinaria(mid,end,v0,k1,k2);
            
}


int main(){

    int N,v0,k1,k2;
    double angle;
    cin >> N;
    for (int i = 0; i < N; i++){
        
        cin >> v0 >> k1 >> k2;
        
        angle = buscaBinaria(0,90,v0,k1,k2);
        cout << degree2rad(angle) << " " << calcPoints(v0,k1,k2,degree2rad(angle)) << "\n";
    }
    
    return 0;
}