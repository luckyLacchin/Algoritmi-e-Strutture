#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std; 

int maxSubStr (int **matrix, int,int); 
int maxsum4(int A[], int n); 

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");  
    int row,column,n;
    in >> row;
    in >> column;  
    int **matrix = new int *[row]; 
    for (int i = 0; i < row; i++) {
        matrix [i] = new int [column]; 
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            in >> matrix [i] [j];  
        }
    }
    int max = maxSubStr (matrix,row,column); 
    out << max << "\n"; 
    cout << "max = " << max << endl; 
    in.close();
    out.close(); 
    for (int i = 0; i < row; i++) {
        delete [] matrix [i]; 
    }
    delete [] matrix; 



    return 0; 
}

int maxsum4(int A[], int n) {
    int maxSoFar = 0;
    int maxHere = 0;
    for (int i=0; i < n; i++) {
        maxHere = max(maxHere+A[i], 0);
        maxSoFar = max(maxSoFar,maxHere);
}
    return maxSoFar;
}

int maxSubStr (int **matrix, int row,int column) {

    int matrixParziale [row] [column]; 
    int maxHere, maxSoFar, maxNow; 
    maxSoFar = 0; 
    maxNow = 0; 
    for (int i = 0; i < row; i++) {
        maxHere = 0; 
        for (int j = 0; j < column; j++) {
            maxHere += matrix[i][j]; 
            matrixParziale [i] [j] = maxHere; 
        }
    }
    for (int j = 0; j < column; j++) {
        cout << "MaxNow = " << maxNow << endl; 
        maxSoFar = max (maxSoFar,maxNow); 
        maxNow = 0;
        for (int i = 0; i < row; i++) {
            maxNow += matrixParziale [i] [j]; 
        }
    }
    for (int i = 0; i < row;i++) {
        cout << endl; 
        for (int j = 0; j < column; j++) {
            cout << matrixParziale[i] [j] << " "; 
        }
    }
    cout << endl;
     
    return maxSoFar; 

} 
