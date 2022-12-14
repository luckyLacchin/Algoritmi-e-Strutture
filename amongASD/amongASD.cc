#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;



void distance (vector<vector<int>> adj, int r) {
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
                distance[v] = distance[v] + 1;
                q.push(v);
            }
        }
    }
}

int main () {

    vector <vector <pair<int,int>>> g;
    vector <int> temp;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int size, semplici, vent, I, S, F, a, b, c;
    in >> size >> semplici >> vent >> I >> S >> F;
    g.resize(size);
    temp.resize(semplici+vent);
    while (in >> a && in >> b && in >> c) {
        g[a].push_back({b,c});
    }


    return 0; 
}