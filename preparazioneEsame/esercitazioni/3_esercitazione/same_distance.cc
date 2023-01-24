#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> distance (vector<vector<int>> adj, int r);

int main () {

    vector<vector<int>> g;
    int s1,s2,s_d = 0, reached = 0;
    vector <int> d1 = distance (g,s1);
    vector <int> d2 = distance (g,s2);
    for (int i = 0; i < d1.size(); i++) {
        if ((d1[i] != -1) && (d2[i] != -1)) {
            ++reached;
        }
        if (d1[i] == d2[i]) {
            ++ s_d;
        }
    }
    cout << "Il numero di nodi raggiungibili sia da s1 che da s2 e': " << reached << endl;
    cout << "Il numero di nodi che si trovano alla stessa distanza da s1 e s2 e': " << s_d << endl;


    return 0;
}

vector <int> distance (vector<vector<int>> adj, int r) {
    vector <int> distance;
    distance.resize (adj.size());
    queue <int> q;
    q.push (r);
    for (int i = 0; i < adj.size(); i++) {
        if (i != r) {
            distance[i] = -1;
        }
    }
    distance[r] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
}