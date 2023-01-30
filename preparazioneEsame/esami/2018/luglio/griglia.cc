#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int griglia (vector<vector<pair<int,pair<int,int>>>> g);

int main () {

    vector<vector<pair<int,pair<int,int>>>> g;
    fstream in ("input.txt");
    int n = 4;
    g.resize(n);
    for (int i = 0; i < n; i++)
        g[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> g[i][j].first;
            g[i][j].second = make_pair(i,j);
        }
    }
    cout << "Il numero di passi per raggiungere l'obiettivo e': " << griglia (g) << endl;
    return 0;
}

int griglia (vector<vector<pair<int,pair<int,int>>>> g) {

    queue <pair<int,pair<int,int>>> q;
    vector<vector<int>> distance;
    distance.resize(g.size());
    for (int i = 0; i < g.size(); i++)
        distance[i].resize(g.size(),-1);
    for (int i = 0; i < g.size(); i++) {
        for (pair<int,pair<int,int>> u : g[i]) {
            if (u.first == 1) {
                q.push(u);
                distance[u.second.first][u.second.second] = 0;
            }
        }
    }
    vector <int> dx = {-1,0,+1,0};
    vector <int> dy = {0,-1,0,+1};
    while (!q.empty()) {
        pair<int,pair<int,int>> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = u.second.first + dx[i];
            int y = u.second.second + dy[i];
            if ((x >= 0 && x < g.size()) && (y >= 0 && y < g.size())) {
                if (distance[x][y] == -1) {
                    distance[x][y] = distance[u.second.first][u.second.second] + 1;
                    q.push(make_pair(g[x][y].first,make_pair(x,y)));
                    if (g[x][y].first == 3)
                        return distance[x][y];
                }
            }


        }
    }
    return -1;
}