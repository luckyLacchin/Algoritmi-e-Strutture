#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int grid (vector<vector<int>> matrix, int size);

int main () {

    vector<vector<int>> matrix;
    ifstream in("input.txt");
    int size = 4;
    matrix.resize(size);
    for (int i = 0; i < size; i++) {
        matrix[i].resize(size);
    }
    for (int i = 0; i < size;i++) {
        for (int j = 0; j < size; j++) {
            in >> matrix[i][j];
        }
    }

    cout << "Il cammino di distanza minimima per andare da 1 a 3 e': " << grid(matrix,size) << endl;



    return 0;
}

int grid (vector<vector<int>> matrix, int size) {

    vector <int> dx = {-1,0,+1,0}; 
    vector <int> dy = {0,-1,0,+1};
    queue <pair<int,int>> q;
    pair<int,int> start;
    pair<int,int> insert;
    vector<vector<int>> distance;
    distance.resize(size);
    for (int i = 0; i < size; i++) {
        distance[i].resize(size,-1);
    }
    int dim = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                q.push(make_pair(i,j));
                distance[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        start = q.front();
        q.pop();
        for (int i = 0; i < size; i++) {
            insert = make_pair(start.first+dx[i],start.second+dy[i]);
            if ((insert.first >= 0) && (insert.first < size) && (insert.second >= 0) && (insert.second < size)) /* vuol dire che sono dentro i limiti della mia tabella*/ {
                if (matrix[insert.first][insert.second] == 3) {
                    //ho finito ma mi devo fare il vettore delle distanze
                    return distance[start.first][start.second]+1;
                }
                else {
                    distance[insert.first][insert.second] = distance[start.first][start.second]+1;
                    q.push(insert);
                }
            } 
        } 
    }
    return -1; // questo accade solo nel caso in cui non trovasse nessuna casella con il numero 3.

}