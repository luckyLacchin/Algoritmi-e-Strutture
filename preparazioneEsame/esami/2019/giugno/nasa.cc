#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int coastLen(vector<vector<int>> m, int n, int r, int c);
void coastLen_aux(vector<vector<int>> m, int n, int r, int c, vector<vector<bool>> &visited, int &costiera);

int main()
{

    int n = 7;
    vector<vector<int>> m;
    m.resize(n);
    for (int i = 0; i < n; i++)
        m[i].resize(n);
    fstream in("input.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> m[i][j];
        }
    }
    int r = 1;
    int c = 3;
    cout << "La linea costiera del mare e' di lunghezza: " << coastLen(m, n, r, c) << endl;

    return 0;
}

int coastLen(vector<vector<int>> m, int n, int r, int c)
{

    vector<vector<bool>> visited;
    visited.resize(n);
    for (int i = 0; i < n; i++)
        visited[i].resize(n, false);
    int costiera = 0;
    coastLen_aux(m, n, r, c, visited, costiera);

    return costiera;
}

void coastLen_aux(vector<vector<int>> m, int n, int r, int c, vector<vector<bool>> &visited, int &costiera)
{

    if ((r >= 0 && r < n) && (c >= 0 && c < n))
    {
        if (!visited[r][c])
        {
            visited[r][c] = true;
            if (m[r][c] < 0)
            {
                coastLen_aux(m, n, r - 1, c, visited, costiera);
                coastLen_aux(m, n, r, c - 1, visited, costiera);
                coastLen_aux(m, n, r + 1, c, visited, costiera);
                coastLen_aux(m, n, r, c + 1, visited, costiera);
            }
            else
            {
                ++costiera;
            }
        }
    }
}
/*invece che fare un parametro costiera potevo direttamente ritornare l'intero*/
