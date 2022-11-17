#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void distance (vector<vector<int>> adj, int start, int finish);

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

    return 0;
}


void distance (vector<vector<int>> adj, int start, int finish) {
    int *result = new int [10000];
    int *distance = new int [adj.size()];
    int count = 0;
    int minPath = -1;
    int path = -1;

    queue <int> q;
    q.push (start);
    for (int i = 0; i < adj.size(); i++) {
        if (i != start) {
            distance[i] = -1;
        }
    }
    distance[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == finish) {
            path = distance [u];
        }
        for (int i = 0; i < adj[u].size(); i++) {
            if (distance[adj[u][i]] == -1) { // || adj[u][i] == finish --> if (distance[u]+1 == adj[u][i] || distance[finish] == -1) {++count} così aumentiamo il numero di path con quella lunghezza.
            /*in realtà dopo dobbiamo mettere un'altra condizione per vedere che non sia minore nel caso lo fosse azzeriamo count, e dopo lo mettiamo count = 1 e andiamo avanti. Così dovrebbe andare*/
                distance[adj[u][i]] = distance[u] + 1;
                q.push(adj[u][i]);
            }
        }
    }
    delete []distance;
    delete [] result;
}

/*allora il problema che dobbiamo valutare è distance che in questo caso dobbiamo tenere conto di tutte le possibilità e non solo di quella minore quindi calcolare la distance solo quando distance[v] = -1 è sbagliato, ma in realtà il giochetto dovremmo farlo per ogni volta. Potremmo fare che ogni volta che becca finish aumentiamo di 1 indipendemente da tutto*/