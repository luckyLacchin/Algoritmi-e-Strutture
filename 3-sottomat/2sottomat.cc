#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std; 

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");  
    int row,column,sol;
    sol = 0; 
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
    int matrixParziale [row] [column]; 
    int maxHere;  
    for (int i = 0; i < row; i++) {
        maxHere = 0; 
        for (int j = 0; j < column; j++) {
            maxHere += matrix[i][j]; 
            matrixParziale [i] [j] = maxHere; 
        }
    }
    
    for(int c1=0;c1<column;c1++) {
      for(int c2=c1;c2<column;c2++){
        int tot=0;
        //visito la colonna con l'algoritmo lineare per la sottosequenza
        for(int r=0;r<row;r++){
          if (c1 != 0) {
	          int cur=matrixParziale[r][c2]-matrixParziale[r][c1-1];
	          tot=max(cur,cur+tot);
	          sol=max(sol,tot);
          }
          else {
            int cur=matrixParziale[r][c2]-0;
	          tot=max(cur,cur+tot);
	          sol=max(sol,tot); 
          }
        }
      } 
    }
    out << sol << "\n"; 
    in.close();
    out.close(); 
    for (int i = 0; i < row; i++) {
        delete [] matrix [i]; 
    }
    delete [] matrix; 



    return 0; 
}
