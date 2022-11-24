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


/* set_union, set_intersection, set_difference, set_symetric_difference */
//end_result = set_intersection(begin1, end1, begin2, end2, begin_result);
//vector < int > res = vi(temp, set_symmetric_difference(all(s1), all(s2), temp));

/*Accumulate can even be used to get the product, specify the predicate of operation */
// double product = accumulate(all(v), double(1), multiplies < double > ());

/*Inner_product can be used to calculated the scalar product between two intervals*/
//int r = inner_product(all(v1), v2.begin(), 0);

/*Deep Search in graph*/
/*
int N; // number of vertices
vvi W; // graph
vi V; // V is a visited flag 

void dfs(int i) {
  if (!V[i]) {
    V[i] = true;
    for_each(all(W[i]), dfs);
  }
}

bool check_graph_connected_dfs() {
  int start_vertex = 0;
  V = vi(N, false);
  dfs(start_vertex);
  return (find(all(V), 0) == V.end());
}
*/