#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;


void distance (vector<vector<int>> adj, int r) {
    int *distance = new int [adj.size()];
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
        for (int i = 0; i < adj[u].size(); i++) {
            if (distance[adj[u][i]] == -1) {
                distance[adj[u][i]] = distance[u] + 1;
                q.push(adj[u][i]);
            }
        }
    }
    delete []distance;
}
