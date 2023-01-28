#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int forest (vector<vector<int>> a, int n);
int forest_aux (vector<vector<int>> a, int n,int x, int y,vector<vector<bool>> &visited);

int main () {

    vector<vector<int>> a;
    fstream in ("input.txt");
    int n = 5;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            in >> a[i][j];
        }
    }

    cout << "La più grande foresta e': " << forest(a,n) << endl;

    return 0;
}

int forest (vector<vector<int>> a, int n) {

    int maxSoFar = 0, maxHere = 0;
    vector <vector<bool>> visited;
    visited.resize(n);
    for (int i = 0; i < n; i++)
        visited[i].resize(n, false);

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (a[i][j] == 1) {
                    maxHere = forest_aux (a,n,i,j,visited);
                    maxSoFar = max(maxHere,maxSoFar);
                }
                else 
                    visited[i][j] = true;
            }
        }
    }
    return maxSoFar;

}

int forest_aux (vector<vector<int>> a, int n,int x, int y,vector<vector<bool>> &visited) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (!visited[x][y])) {
        visited[x][y] = true;
        if (a[x][y] == 0)
            return 0;
        else {
            return 1 + forest_aux(a,n,x+1,y,visited) + forest_aux(a,n,x-1,y,visited) + forest_aux(a,n,x,y-1,visited) + forest_aux(a,n,x,y+1,visited);
        }
    }
    else
        return 0;
}