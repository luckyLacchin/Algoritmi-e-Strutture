#include <iostream> 
#include <fstream>

using namespace std; 


void mergeSort (int *array, int first, int last); 
void merge (int *array, int first, int middle, int last); 

int main () {

    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int n,inizio,fine; 
    in >> n;
    int *start = new int [n]; 
    int *end = new int [n];
    int i = 0;
    while ((in >> start[i]) && (in >> end[i])) {
        ++i;
    }
    mergeSort(start,0,n-1);
    mergeSort(end,0,n-1);
    int j = 0, temp = 0;
    int max = temp; 
    while (j < n-1) {
        if (start[j+1] > end[j]) {
            temp = start[j+1] - end[j];
            if (temp>max) {
                max = temp; 
                inizio = end[j];
                fine = start[j+1];
            }
        }
        ++j;

    }
    if (max != 0) {
        out << inizio << " " << fine << endl;
    }
    else 
        out << 0;

    in.close(); 
    out.close(); 
    delete []start;
    delete []end;
    return 0;
}

void mergeSort (int *array, int first, int last) {

    int middle = (first + last) / 2; 
    if (first < last) {
        mergeSort(array,first,middle);
        mergeSort(array,middle+1,last);
        merge (array,first,middle,last); 
    }
    else {
    }

}

void merge (int *array, int first, int middle, int last) {

    int *temp = new int [last-first+1];
    int i = first;
    int j = middle+1; 
    int k = 0;
    while (k < last-first+1) {
        if ((i <= middle) && (j > last || array[i] <= array[j])) {
            temp[k] = array[i];
            ++i;
        }
        else if ((j <= last) && (i > middle || array[i] > array[j])) {
            temp[k] = array[j]; 
            ++j;
        }

        ++k; 
    }
    int l = first;
    for(int m = 0; m < last-first+1;m++) {
        array[l] = temp[m];
        ++l;
    }
    delete []temp;

}