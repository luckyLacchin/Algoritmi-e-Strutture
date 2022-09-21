#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std; 

int maxSubStr (int *A, int dim); 

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");  
    int dim,n;
    in >> dim; 
    int *A = new int [dim]; 
    for (int i = 0; i < dim; i++) {
        in >> n; 
        A[i] = n;
    }
    int max = maxSubStr (A,dim); 
    out << max << "\n"; 
    cout << "nuova modifica" << endl;
    in.close();
    out.close(); 
    delete [] A; 



    return 0; 
}

int maxSubStr (int *A, int dim) {
    int maxSoFar, maxNow;
    maxSoFar = 0; 
    maxNow = 0; 
    for (int i = 0; i < dim; i++) {
        maxNow = max (maxNow+A[i],0); 
        maxSoFar = max (maxNow,maxSoFar);
    }
    return maxSoFar; 
}
