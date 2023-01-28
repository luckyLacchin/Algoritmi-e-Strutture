/*Ricordati che si dice che non esista un ordinamento topologico quando il grafo contiene cicli, invece si dice che un grafo abbia più ordinamenti topologici quando ci sono più di un nodo che non ha archi entranti*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maybeTopSort(vector<vector<int>> &g);
bool hasCycle (vector<vector<int>> &g);
bool hasCycleRec (vector<vector<int>> &g, int u, vector<int> &dt, vector <int> &ft, vector <bool> &visited, int time);
bool hasMoreEntries (vector<vector<int>> &g, int start);
vector<vector<int>> transpose(vector<vector<int>> &g);

int main () {

    vector<vector<int>> g;

    cout << "Il risultato riguardo all'ordinamento topologico del grafo e': " << maybeTopSort(g) << endl;

    return 0;
}

int maybeTopSort(vector<vector<int>> &g) {

    if (hasCycle(g))
        return 0;
    else if (hasMoreEntries(g,0))
        return 2;
    
    return 1; 
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
/*credo di poter fare una normalissima bfs in cui quando entro dentro un nodo, lo metto = true nell'indice del vettore!*/
bool hasMoreEntries (vector<vector<int>> &g, int start) {

    queue <int> q;
    q.push(start);
    vector <bool> entries;
    vector <bool> visited;
    entries.resize(g.size(),false);
    visited.resize(g.size(),false);
    int count = g.size(); /*contatore dei nodi senza archi entranti*/
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        for (int v : g[u]) {
            if (entries[v] == false) {
                entries[u] = true;
                q.push(v);
                --count; 
            }
        }
    }
    vector<vector<int>> gt = transpose (g);
    queue <int> q;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        for (int v : g[u]) {
            entries[u] = true;//ho girato i lati se esiste un v vuol dire che nel grafo reale c'è una lato entrante su u!
            --count; 
        }
    }
    
    return (count > 1); // se è maggiore di 1 vuol dire che posso partire da più nodi per fare il mio ordine topologico
}


/*Credo che sto facendo solo algoritmi di complessità
O(n+m) dunque scialla*/

vector<vector<int>> transpose(vector<vector<int>> &g) {

    vector<vector<int>> gt;
    gt.resize(g.size());
    for (int u = 0; u < g.size(); u++) {
        for (int v : g[u]) {
            gt[v].push_back(g[u][v]);
        }
    }
    return gt;
}