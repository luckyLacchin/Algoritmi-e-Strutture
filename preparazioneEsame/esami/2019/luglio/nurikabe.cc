#include <vector>
#include <iostream>

using namespace std;

bool isSolution (vector<vector<int>> &g, vector<vector<int>> &s, int n);
int isSolution_aux (vector<vector<int>> &g, vector<vector<int>> &s, vector<vector<int>> &visited,int i,int j, int color); 


int main () {

    vector<vector<int>> g;
    vector<vector<int>> s;
    int n;
    g.resize(n);
    s.resize(n);


    cout << "La matrice s è una soluzione del problema di Nurikabe? " << (isSolution(g,s,n) ? "Si": "No") << endl;
    return 0;
}

bool isSolution (vector<vector<int>> &g, vector<vector<int>> &s, int n) {
    
    vector<vector<int>> visited;
    visited.resize(g.size());
    for (int i = 0; i < g.size(); i++)
        visited[i].resize(g.size(), 0);
    int wall = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g.size(); j++) {
            if ((g[i][j] > 0) && (visited[i][j] == 1))
                return false;
            else if ((g[i][j] > 0) && (s[i][j] == 1))
                return false;
            else if (g[i][j] > 0) {
                if (isSolution_aux (g,s,visited,i,j,0) != g[i][j])    
                    return false;
            }
            else if ((i < n-1) && (j < n-1) && (s[i][j] + s[i+1][j] + s[i][j+1] + s[i+1][j+1] == 4))
                return false;

            if (visited[i][j] == 0 && s[i][j] == 1) {
                wall += 1;
                isSolution_aux (g,s,visited,i,j,1);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g.size(); j++)
        sum+= visited[i][j];
    }
    return (wall == 1) && (sum = g.size()*g.size());
}

int isSolution_aux (vector<vector<int>> &g, vector<vector<int>> &s, vector<vector<int>> &visited, int i,int j, int color) {

    if (i < 0 || i >= g.size() || j < 0 || j >= g.size() || visited[i][j] == 1 || s[i][j] != color)
        return 0;
    else {
        visited[i][j] = 1;
        return 1 + isSolution_aux(g,s,visited,i-1,j,color) + isSolution_aux(g,s,visited,i,j-1,color) + isSolution_aux(g,s,visited,i+1,j,color) + isSolution_aux(g,s,visited,i,j+1,color);
    }
}
