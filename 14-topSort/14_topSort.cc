#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;


stack <int> topSort (vector<vector<int>> g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);

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
    stack <int> res = topSort (adj,nodi);
    for (int i = 0; i < nodi; i++) {
        out << res.top() << " ";
        res.pop();
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