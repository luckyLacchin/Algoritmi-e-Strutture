#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;


stack <int> topSort (vector<vector<int>> g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
vector <vector <int>> transpose (vector<vector<int>> &g, int nodi);
void ccdfs (vector<vector<int>> g, int counter, int u, int *id);
int *scc(vector<vector<int>> &g, int nodi);

int main () {
    vector <vector <int>> adj;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi;
    in >> nodi;
    in >> archi;
    int a,b;
    adj.resize(nodi);
    for(int i=0;i<archi;i++){
        in >> a;
        in >> b;
        adj[a].push_back(b);
    }
    
    return 0;
}

stack <int> topSort (vector<vector<int>> g, int nodi) {

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
    cout << s.top() << endl;
}

vector <vector <int>> transpose (vector<vector<int>> &g,int nodi) {

    vector<vector<int>> trasposta;
    trasposta.resize(nodi);
    for (int i = 0; i < nodi; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            trasposta[j].push_back(i);
        }
    }
    return  trasposta;
}

int *cc (vector<vector<int>> &g, int nodi) {

    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++){
        id[i] = 0; 
    }
    int counter = 0; 
    for (int u = 0; u < nodi; u++) {
        if (id[u]==0) {
            counter = counter + 1;
            ccdfs (g,counter,u,id);
        }
    }
}

void ccdfs (vector<vector<int>> g, int counter, int u, int *id) {
    id[u] = counter;
    for (int v = 0; v < g[u].size(); v++) {
        if(id[v] == 0) {
            ccdfs (g,counter,v,id);
        }
    }
}

int *scc(vector<vector<int>> &g, int nodi) {
    stack s = topSort (g, nodi);
    vector<vector<int>> trasposta = transpose (g,nodi);
    return cc(trasposta,nodi); 
}