#include <fstream> 
#include <iostream>

using namespace std; 

int main (int argc, char *argv[]) {

    ifstream in ("input.txt"); 
    ofstream out ("output.txt"); 
    int n1,n2,somma; 
    in >> n1 >> n2; 
    somma = n1 + n2; 
    out << somma; 
    return 0; 

}
