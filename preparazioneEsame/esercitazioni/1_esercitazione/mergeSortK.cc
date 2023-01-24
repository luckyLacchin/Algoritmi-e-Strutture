#include <iostream>
#include <vector>

using namespace std;

void mergeSortK (int vec[], int k, int first, int last);
void mergeK (int v[], int first,int dim);

int main () {

    int dim =  9;
    int vec[dim];

    mergeSortK (vec,4,0,dim-1);
    return 0;
}

void mergeSortK (int vec[], int k, int first, int last) {
    if (last>first) {
        int dim = (last - first) / k;
        int i = first; 
        while (i <= last) {
            mergeSortK(vec,k,i,i+dim-1);
            i += dim;
        }
        mergeK(vec,first,dim);
    }
}

void mergeK(int v[], int first, int dim)
{
}
