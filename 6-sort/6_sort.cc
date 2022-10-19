#include <iostream> 
#include <fstream>

using namespace std; 

int n;

void sort (int *array, int first, int last); 
void printArray (int *array, int n);
void merge (int *array, int first, int middle, int last);

int main () {

    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int i = 0;
    in >> n;
    int *array = new int [n]; 
    while (in >> array[i]) {
        ++i;
    }
    printArray(array,n); 
    sort(array,0, n-1); 
    printArray(array,n); 
    for (int i = 0; i < n; i++) {
        out << array[i] << " ";
    }

    in.close(); 
    out.close();
    delete array;
}

void printArray (int *array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; 
    }
    cout << endl; 
}

void sort (int *array, int first, int last) {

    int middle = (first + last) / 2; 
    if (first < last) {
        sort(array,first,middle);
        sort(array,middle+1,last);
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
    delete temp;

}