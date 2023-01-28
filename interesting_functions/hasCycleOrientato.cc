#include <vector>

using namespace std;

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