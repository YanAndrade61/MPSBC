#include<bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

typedef vector < vi > vvi;

typedef pair < int, int > ii;

//Retorna tamanho da estrutura
#define sz(a)\
 int((a).size())

//Retorna 
#define pb push_back

//Retorna inicio e fim da estrutura
#define all(c) c.begin(), c.end()

//Loop para estruturas
#define tr(c, it)\
 for (typeof (c).begin() it = c.begin(); it != c.end(); it++)

//For others
#define present(c, x)(c.find(x) != c.end())

//For vector
#define cpresent(c, x)(find(allc, x) != c.end())

// Copy containers
// vector < int > v1;
// vector < int > v2;
// // … 
// // Now copy v2 to the end of v1
// v1.resize(v1.size() + v2.size());
// // Ensure v1 have enough space
// copy(all(v2), v1.end() - v2.size());
// // Copy v2 elements right after v1 ones