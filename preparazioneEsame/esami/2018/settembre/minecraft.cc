#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

float minecraft (vector<vector<int>> &g);
void  minecraft_aux (vector<vector<int>> &g, vector<vector<bool>> &visited, int i, int j, float &sum, float &count);

int main () {

    int n = 5;
    fstream in ("input.txt");
    vector<vector<int>> g;
    g.resize(n);
    for (int i = 0; i < n; i++)
        g[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            in >> g[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout <<  g[i][j] << " ";
        cout << endl;
    }

    cout << "L'isola con l'altitudine media maggiore e': " << minecraft(g) << endl;
}

float minecraft (vector<vector<int>> &g) {

    float maxSoFar = 0;
    float sum = 0, count = 0;
    float maxHere = 0;
    vector<vector<bool>> visited;
    visited.resize(g.size());
    for (int i = 0; i < g.size(); i++)
        visited[i].resize(g.size(),false);
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g.size(); j++) {
            if (!visited[i][j]) {
                if (g[i][j] <= 0)
                    visited[i][j] = true;
                else {
                    minecraft_aux(g,visited,i,j,sum,count);
                    maxHere = sum / count;
                    maxSoFar = max(maxSoFar,maxHere);
                    sum = count = 0;

                }
            }
        }
    }
    return maxSoFar; 
}

void  minecraft_aux (vector<vector<int>> &g, vector<vector<bool>> &visited, int i, int j, float &sum, float &count) {

    if ((i >= 0 && i < g.size()) && (j >= 0 && j < g.size())) {
        if (!visited[i][j]) {
            visited[i][j] = true;
            if (g[i][j] > 0) {
                //cout << "g[i][j] = " << g[i] [j] << endl;
                sum += g[i][j];
                ++count;
                minecraft_aux(g,visited,i-1,j,sum,count);
                minecraft_aux(g,visited,i,j-1,sum,count);
                minecraft_aux(g,visited,i+1,j,sum,count);
                minecraft_aux(g,visited,i,j+1,sum,count);
            }
        }

    }
}