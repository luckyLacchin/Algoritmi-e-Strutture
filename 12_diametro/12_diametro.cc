#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//void d (vector<vector<int>> adj, int u)

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
        adj[b].push_back(a);
    }
    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++) {
        id[i] = 0;
    }


    int res = 0;
    ++res;
    out << res;
    delete [] id;
    return 0;
}