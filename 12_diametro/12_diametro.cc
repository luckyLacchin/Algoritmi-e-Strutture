#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void distance (vector<vector<int>> adj, int r, int &maxDistance);
int iterativeDistance (vector<vector<int>> adj);

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
        adj[b].push_back(a);
    }
    int res = iterativeDistance (adj);
    out << res;
    return 0;
}

int iterativeDistance (vector<vector<int>> adj) {
    int maxDistance = 0;
    for (int i = 0; i < adj.size(); i++) {
        distance(adj,i,maxDistance);

    }
    return maxDistance;
}


void distance (vector<vector<int>> adj, int r, int &maxDistance) {
    int *distance = new int [adj.size()];
    queue <int> q;
    q.push (r);
    int max; // questo intero lo uso per indicare l'indice della distance maggiore da r!
    for (int i = 0; i < adj.size(); i++) {
        if (i != r) {
            distance[i] = -1;
        }
    }
    distance[r] = 0;
    max = r;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            if (distance[adj[u][i]] == -1) {
                distance[adj[u][i]] = distance[u] + 1;
                q.push(adj[u][i]);
                if (distance[max] < distance[adj[u][i]]) { //dovrebbe essere sempre vera
                    max = adj[u][i];
                }
            }
        }
    }
    if (distance[max] > maxDistance) {
        maxDistance = distance[max];
    }
    delete []distance;
}
// il punto è che la complessità è O(n(m+n)). Quindi o è O(nm) o O(n^2). Dovrei chiedere agli esercitatori se c'è un modo con meno complessità.