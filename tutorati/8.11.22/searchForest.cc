#include <iostream>
#include <fstream>

using namespace std;

int searchForest (int **A, int n);
int forest (int **A, bool **visitato,int i, int j, int n);

int main () {

    int n = 5;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int [n];
    }
    int res = searchForest (matrix,n);



    for (int i = 0; i < n; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}

int searchForest (int **A, int n) {
    int max = 0;
    int temp = 0;
    bool **visitato = new bool *[n];
    for (int i = 0; i < n; i++) {
        visitato[i] = new bool [n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == 1) {
                if (visitato[i][j] == false) {
                    temp = forest (A,visitato,i,j,n);
                }
            }
            else {
                visitato[i][j] == false; //metto subito true le caselle 0 che incontro
            }
        }
    }

    for (int i = 0; i < n; i++) {
        delete [] visitato[i];
    }
    delete [] visitato;
}

int forest (int **A, bool **visitato,int i, int j, int n) {
    
    if(visitato[i][j] == false && visitato[i][j] == 1) {
        visitato[i][j] = true;
        if (i> 0 && j < 0 && i < n-1 && j < n-1) {
            return 1 + forest (A,visitato,i-1,j,n) + forest (A,visitato,i,j-1,n) + forest (A,visitato,i,j+1,n) + forest (A,visitato,i+1,j,n);
        }
    }
    else {
        visitato[i][j] = true; //potrebbe essere uguale a 0, lo metto true così non lo visito più.
        return 0;
    }
}
