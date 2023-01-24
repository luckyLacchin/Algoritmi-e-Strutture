#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int max_sum (vector<vector<int>> &matrix, int &righe, int &colonne);

int main () {
    
    vector<vector<int>> matrix;
    vector<vector<int>> matrixSeq;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int righe,colonne,temp;

    in >> righe >> colonne;
    matrix.resize(righe);
    for (int i = 0; i < righe; i++) {
        matrix[i].resize(colonne);
    }
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            in >> temp;
            matrix[i][j] = temp;
            //cout << "matrix[i][j] = " << matrix[i][j] << endl;
        }
    }
    matrixSeq.resize(righe);
    for (int i = 0; i < righe; i++) {
        matrixSeq[i].resize(colonne);
    }
    for (int i = 0; i < righe; i++) {
        temp = 0;
        for (int j = 0; j < colonne; j++) {
            //cout << "matrix[i][j] = " << matrix[i][j] << endl;
            temp += matrix[i][j];
            matrixSeq[i][j] = temp;
            //cout << "matrixSeq[i][j] = " << matrixSeq[i][j] << endl;
        }
    }
    
    out << max_sum (matrixSeq, righe, colonne);

    return 0;
}

int max_sum (vector<vector<int>> &matrixSeq, int &righe, int &colonne) {

    int tot = 0, sol = 0, cur = 0;
    for (int i = 0; i < colonne; i++) {
        for (int j = i; j < colonne; j++) {
            tot = 0; 
            for (int k = 0; k < righe; k++) {
                if (i != 0) {
                    cur = matrixSeq[k][j] - matrixSeq[k][i-1];
                    tot = max (cur,tot+cur);
                    sol = max (tot,sol);
                }
                else {
                    cur = matrixSeq[k][j] - 0;
                    tot = max (cur,tot+cur);
                    sol = max (tot,sol);
                }
            }
        }
    }
    
    return sol;
}