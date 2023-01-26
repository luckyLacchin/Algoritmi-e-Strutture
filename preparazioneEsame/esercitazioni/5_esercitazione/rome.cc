//questo esercizio è sbagliato, ho letto male la consegna!
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;

bool rome (vector<vector<int>> &g,int v);
bool faccio_io (vector<vector<int>> &g);
void dfs_rec (vector<vector<int>> &g, int u, vector <bool> &visited, vector<int> &reached);

int main () {

    vector <vector <int>> g;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t,s, nodi, archi;
    in >> nodi >> archi;
    g.resize(nodi);
    while ((in >> t) && (in  >> s)) {
        g[t].push_back(s);
    }
    int v = 3;
    cout << "v e' un vertice di tipo Roma? " << (rome(g,v) ? "Si" : "No") << endl;
    cout << "Esiste Roma nel nostro grafo: " << (faccio_io(g) ? "Si" : "No") << endl;
    
    return 0; 
}

bool rome (vector<vector<int>> &adj, int r) {
    vector <int> distance;
    distance.resize (adj.size(),-1);
    queue <int> q;
    q.push (r);
    distance[r] = 0;
    int count = adj.size(); //contatore per i nodi sul totale raggiunti, se arriva a zero vuol dire che ho raggiunto tutti i nodi;
    --count; 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
                --count;
            }
        }
    }
    if (count == 0)
        return true;
    else
        return false;
}

bool faccio_io (vector<vector<int>> &g) {

    vector <int> reached;
    vector <bool> visited;
    visited.resize(g.size(),false);
    reached.resize(g.size(),1); //metto 1 perché almeno raggiungo sè stessi;
    for (int u = 0; u < g.size(); u++) {
        if (!visited[u]) {
            dfs_rec(g,u,visited,reached);
        }
    }
    for (int i : reached) {
        if (i == g.size())
            return true;
    }
    return false; // ma così diventa O(n+m) + O(n) = O(n+m);
    
   /*
    if (g.size()>=1)
        return dfs_rec(g,0,visited,reached);
    else
        return false;
        */
}


void dfs_rec (vector<vector<int>> &g, int u, vector <bool> &visited, vector<int> &reached) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs_rec(g,v,visited,reached);
        }
        reached[u] += reached[v];
    }
}
