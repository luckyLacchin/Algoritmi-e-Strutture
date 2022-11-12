#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int cc (vector <vector <int>> adj, vector <int> lista, int partenza,int nodi);
void ccdfs (vector<vector<int>> adj, int counter, int u, int *id, vector <int > temp, int partenza, int &index);

int main () {
    vector <vector <int>> adj;
    vector <int> lista;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, partenza, temp, index;
    in >> nodi;
    in >> archi;
    in >> partenza;
    int start, finish;
    int a,b;
    for(int i=0;i<archi;i++){
        in >> a;
        in >> b;
        adj[a].push_back(b);
    }
    
    
    int res = cc(adj,lista,partenza,nodi); 
    out << res;

    return 0;
}

int cc (vector <vector <int>> adj, vector <int> lista, int partenza, int nodi) {
    int index = -1;
    int *id = new int [nodi];
    vector <int> temp;
    for (int i = 0; i < lista.size(); i++) {
        id[i] = 0;
    }
    int counter = 0;
    for (int u = 0; u < lista.size(); u++) {
        if(id[u] == 0) {
            counter = counter + 1;
            ccdfs (adj,counter,u,id, temp, partenza, index);
        }
    }
    cout << temp[index] << endl;
    return temp[index];

}

void ccdfs (vector<vector<int>> adj, int counter, int u, int *id, vector <int> temp, int partenza, int &index) {
    if (u == partenza) {
        index = counter;
    }
    id[u] = counter;
    ++temp[counter];
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == 0) {
            ccdfs (adj,counter,adj[u][i],id,temp, partenza, index);
        }
    }

}