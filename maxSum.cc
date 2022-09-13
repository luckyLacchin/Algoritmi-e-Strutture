#include <iostream>

using namespace std;

int maxsum4 (int A[], int n); 

int main () {
    int A [] = {1,3,4,-8,2,3,-1,3,4,-3,10}; 
    int dim = 11; 
    cout << maxsum4 (A,dim) << endl; 
    cout << "lol" << endl; 
    cout << "ciao tutto bene" << endl; 
    cout << "questa è la seconda branch!"

    return 0; 
}

int maxsum4 (int A[], int n) {
    int maxSoFar = 0; 
    int maxHere = 0; 

    for (int i = 0; i < n; i++) {
        maxHere = max(maxHere+A[i],0); 
        maxSoFar = max (maxSoFar,maxHere); 
    }
    return maxSoFar; 
}