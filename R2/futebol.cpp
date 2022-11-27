#include <bits/stdc++.h>

using namespace std;

bool cmpStrings(const string& a, const string& b)
{
    unsigned int sz;
    if (b.size() > a.size())
        sz = a.size();
    else
        sz = b.size();
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) > tolower(b[i]))
            return false;
    return true;
}

bool fn(const pair<string,tuple<int,int,int,int>> &x,const pair<string,tuple<int,int,int,int>> &y){

    if(get<0>(x.second) != get<0>(y.second)){
        return get<0>(x.second) > get<0>(y.second);
    }
    else if(get<2>(x.second)-get<3>(x.second) != get<2>(y.second)-get<2>(y.second)){
        return get<2>(x.second)-get<3>(x.second) > get<2>(y.second)-get<2>(y.second);
    }
    else if(get<2>(x.second) != get<2>(y.second)){
        return get<2>(x.second) > get<2>(y.second);
    }

    return cmpStrings(x.first, y.first);

}


int main(){

    int T,G,golA,golB,qtd=0;
    char t;
    int max=0;
    string timeA,timeB;

    vector<vector<pair<string,tuple<int,int,int,int>>>> tabelas;
    while(true){

        cin >> T >> G;
        if(T == 0 && G == 0)break;
        qtd++;
        //tuple<int,int,int,int> == pontos, qtd_jogos, gol_feitos, gols_sofridos
        vector<pair<string,tuple<int,int,int,int>>> tabela(T);
        
        map<string,int> idx;
        for (int i = 0; i < T; i++){
            cin >> timeA;
            max = (int)timeA.size() > max ? (int)timeA.size() : max;
            tabela[i] = make_pair(timeA,make_tuple(0,0,0,0));
            idx[timeA] = i;
        }
        for (int i = 0; i < G; i++){
            cin >> timeA >> golA >> t >> golB >> timeB;

            get<2>(tabela[idx[timeA]].second) += golA;
            get<3>(tabela[idx[timeA]].second) += golB;
            get<2>(tabela[idx[timeB]].second) += golB;
            get<3>(tabela[idx[timeB]].second) += golA;
            
            get<1>(tabela[idx[timeA]].second) += 1;
            get<1>(tabela[idx[timeB]].second) += 1;
            
            if(golA > golB)
                get<0>(tabela[idx[timeA]].second) += 3;
            else if(golB > golA)
                get<0>(tabela[idx[timeB]].second) += 3;
            else{
                get<0>(tabela[idx[timeA]].second) += 1;
                get<0>(tabela[idx[timeB]].second) += 1;
            }
        }
        sort(tabela.begin(),tabela.end(),fn);

        tabelas.push_back(tabela);
    }
    for (int i = 0; i < qtd; i++)
    {
        int pos = 0,up=1;
        cout << fixed << setprecision(2);
        for (int j = 0; j < (int)tabelas[i].size(); j++){
            
            if(up){
                pos += up;
                cout << pos << '.';
                cout << setfill(' ') << setw(max+1);
                up = 0;
            }
            else{
                cout << setfill(' ') << setw(max+1+2);
            }
            if((j < (int)tabelas[i].size()) && tabelas[i][j].second != tabelas[i][j+1].second){
                up = 1;
            }
            cout << tabelas[i][j].first;
            
            printf(" %3d %3d %3d %3d %3d ",
                get<0>(tabelas[i][j].second),
                get<1>(tabelas[i][j].second),
                get<2>(tabelas[i][j].second),
                get<3>(tabelas[i][j].second),
                get<2>(tabelas[i][j].second)-get<3>(tabelas[i][j].second)
            );
            cout << setfill(' ') << setw(6);
            if(get<1>(tabelas[i][j].second) == 0)
                cout << "N/A";
            else
                cout << (get<0>(tabelas[i][j].second)/(get<1>(tabelas[i][j].second)*3.0))*100.0; 
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}