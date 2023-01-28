#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool canItalyWin (vector<vector<int>> g, int s);
bool hasCycleRec (vector<vector<int>> &g, int u, vector<int> &dt, vector <int> &ft, vector <bool> &visited, int time);
stack <int> topSort (vector<vector<int>> &g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
bool hasCycle (vector<vector<int>> &g);
void printOrder (vector<vector<int>> &g, int s);

int main () {
    vector<vector<int>> g;
    int n;
    g.resize(n);
    int s;
    cout << "L'italia vincerà il mondiale? " << (canItalyWin (g,s)? "Si":"No") << endl;
}

bool canItalyWin (vector<vector<int>> g, int s) {
    if (g.size() == 1)
        return true; //vuol dire che c'è solo l'italia
    else if (g[s].size() == 0)
        return false; //vuol dire che l'Italia non batte nessuna squadra quindi è impossibile trovare una combinazione in cui possa vincere;
    else if (hasCycle(g)){
        vector<bool> visited;
        vector<int> entry;
        entry.resize(g.size(),0);
        visited.resize(g.size(),false);
        queue <int> q;
        q.push(g[s][0]);
        for (int u = 0; u < g.size(); u++) {
            for (int v : g[u]) {
                ++entry[v];
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                entry[v] = entry[v] - 1;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
                if (entry[s] == 0)
                    return true;
            }
        }
    }
    else {
        stack <int> p = topSort(g,g.size());
        if (p.top() == s)
            return true;
        else
            return false;
    }
    return false;
}

bool hasCycle (vector<vector<int>> &g) {

    vector <int> dt;
    vector <int> ft;
    vector <bool> visited;
    dt.resize(g.size());
    ft.resize(g.size());
    visited.resize(g.size()); 
    for (int u = 0; u< g.size(); u++) {
        if (!visited[u])
            if (hasCycleRec(g,u,dt,ft, visited,0))
                return true;
    }
    return false;

}
bool hasCycleRec (vector<vector<int>> &g, int u, vector<int> &dt, vector <int> &ft, vector <bool> &visited, int time) {
    visited[u] = true;
    time = time + 1;
    dt[u] = time;
    for (int v : g[u]) {
        if (dt[u] == 0) {
            if(hasCycleRec(g,v,dt,ft,visited,time))
                return true;
        }
        if (dt[u]<dt[v] && ft[v] == 0)
            return true;
    }
    time = time + 1; 
    ft[u] = time;
    return false;
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

void printOrder (vector<vector<int>> &g, int s) {

}

/*vedere la soluzione: http://disi.unitn.it/~montreso/asd/compiti/18-06-28.soluzione.pdf Anche se credo che anche la mia soluzione vada bene, alla fine.*/