#include <iostream>
#include <vector>

using namespace std;

struct nodo {
    int value;
    int key;
    vector<int> adj;
};

int main () {

    vector<vector<int>> matrix;
    matrix.resize(4);
    for (int i = 0; i < 4; i++) {
        matrix[i].resize(4);
    }
    for (int i = 0; i < 4;i++) {
        for (int j = 0; j < 4; j++) {
            //matrix[i][j] = 
        }
    }

    return 0;
}