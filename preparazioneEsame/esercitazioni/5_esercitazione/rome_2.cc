#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <stack>

using namespace std;

bool rome (vector<vector<int>> &g,int v);
vector <vector <int>> transpose (vector<vector<int>> &g,int nodi);
stack <int> topSort (vector<vector<int>> &g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
bool rome_2 (vector<vector<int>> g);

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
    int v = 0;
    vector <vector<int>> Gt = transpose(g,g.size());
    cout << "v e' un vertice di tipo Roma? " << (rome(Gt,v) ? "Si" : "No") << endl;

    cout << "Esiste un vertice di tipo Roma? " << (rome_2(g) ? "Si" : "No") << endl;

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

bool rome_2 (vector<vector<int>> g) {

    vector <vector <int>> Gt = transpose(g,g.size());
    stack <int> top = topSort(g,g.size());
    int maybeRome = top.top();
    return rome(Gt,maybeRome);


}

vector <vector <int>> transpose (vector<vector<int>> &g,int nodi) {

    vector<vector<int>> trasposta;
    trasposta.resize(nodi);
    for (int i = 0; i < nodi; i++) {
        for (int j : g[i]){
            trasposta[j].push_back(i);
        }
    }
    return  trasposta;
}

stack <int> topSort (vector<vector<int>> &g, int nodi) {

    stack <int> s;
    bool *visited = new bool [nodi];
    for (int i = 0; i < nodi; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < nodi; i++) {
        if (visited[i] == false) {
            ts_dfs(g,i,visited,s);
        }
    }

    delete [] visited;
    return s;
}

void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s) {
    visited[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if(visited[g[u][i]] == false) {
            ts_dfs (g,g[u][i],visited,s);
        }
    }
    s.push(u);
}