#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;



void distance (vector <vector <pair<int,int>>> g, int r) {
    vector <int> distance;
    distance.resize (g.size());
    queue <int> q;
    q.push (r);
    for (int i = 0; i < g.size(); i++) {
        if (i != r) {
            distance[i] = -1;
        }
    }
    distance[r] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (pair<int,int> v: g[u]) {
            int i = v.first;
            if (distance[i] == -1) {
                distance[i] = distance[i] + 1;
                q.push(i);
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