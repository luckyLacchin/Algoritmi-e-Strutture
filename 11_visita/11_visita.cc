#include <iostream>
#include <vector>
#include <fstream>
#include <stack>


using namespace std;

//int cc (vector <vector <int>> adj, vector <int> lista, int partenza,int nodi);
void ccdfs (vector<vector<int>> adj, int u, int *id, int &res);
void dfs (vector<vector<int>> adj, int u);


int main () {
    vector <vector <int>> adj;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, partenza;
    in >> nodi;
    in >> archi;
    in >> partenza;
    int start, finish;
    int a,b;
    adj.resize(nodi);
    for(int i=0;i<archi;i++){
        in >> a;
        in >> b;
        adj[a].push_back(b);
    }
    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++) {
        id[i] = 0;
    }


    int res = 0;
    ccdfs (adj,partenza,id,res);
    ++res;
    out << res;
    delete [] id;
    return 0;
}

void ccdfs (vector<vector<int>> adj, int u, int *id, int &res) {
    if (id[u] == 0) {
        id[u] = 1; //non mi interessa calcolare le c.c. basta qualsiasi numero
    }
    for (int i = 0; i < adj[u].size(); i++) {
        if (id[adj[u][i]] == 0) {
            ++res;
            ccdfs (adj,adj[u][i],id,res);
        }
    }

}

void dfs (vector<vector<int>> adj, int u) {
    
    stack <int> s;
    
    
}