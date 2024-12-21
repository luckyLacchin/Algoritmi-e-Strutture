#include <iostream> 
#include <fstream>

using namespace std; 


void mergeSort (int *array, int first, int last); 
void merge (int *array, int first, int middle, int last); 
bool equal (int *array, int *copy, int n);
int binaryIndex (int *array, int first, int last, int elem);
void printArray (int *array, int n);
int main () {

    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int n; 
    in >> n;
    int *array = new int [n];
    int *copy = new int [n];
    int temp, k = 0, scambi = 0, index1, index, costo = 0; 
    while (in >> temp) {
        array[k] = temp;
        copy[k] = temp;
        ++k;
    } 
    mergeSort(copy,0,n-1);

    for (int i = 0; (i < n) && (!equal(array,copy,n));i++) {
        index = binaryIndex (copy,0,n-1,array[i]);
        index1 = binaryIndex (copy,0,n-1,array[index]);
        if (index1 == i && (index != i)) {
            cout << "array[i] = " << array[i] << endl;
            cout << "array[index] = " << array [index] << endl;
            costo += array[i] + array[index];
            //vuol dire che sono perfettamente opposti e sono i primi ad essere scambiati!
            temp =array[index];
            array[index] = array[i];
            array[i] = temp; //tutto questo è un semplice swap!
            ++scambi;
        
        }
    }
    printArray(array,n);
    for (int i = 0; (i < n) && (!equal(array,copy,n)); i++) {
        index = binaryIndex (copy,0,n-1,array[i]); //così troviamo il suo indice nell'array ordinato
        cout << "index = " << index << endl;
        if (index != i) { // se l'elemento non è già nella sua posizione ordinata dobbiamo spostarlo
            costo += array[i] + array[index];
            cout << "array[i] = " << array[i] << endl << endl;
            temp =array[index];
            array[index] = array[i];
            array[i] = temp; //tutto questo è un semplice swap!
            ++scambi;
            --i;
        }
        
    }
    out << scambi << " " << costo << endl;
    delete [] array;
    delete [] copy;
    in.close(); 
    out.close(); 
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

int binaryIndex (int *array, int first, int last, int elem) {

    int middle = (first+last) / 2; 
    if (first <= last) {
        if (elem == array[middle]) {
            //cout << "Elemento trovato!" << endl;
            return middle; 
        }
        if (elem > array[middle]) {
            return binaryIndex(array,middle+1,last,elem);
        }
        else if (elem < array[middle]) {
            return binaryIndex(array,first,middle-1,elem);
        }
    }
    else {
        cout << "elemento = " << elem << endl; 
        //cout << "Errore! Elemento non presente nell' array" << endl; 
        return -1; 
    }  
}

bool equal (int *array, int *copy, int n) {
    bool corretto = true;
    for (int i = 0; i < n && (corretto); i++) {
        if (array[i] != copy[i])
            corretto = false;
    }
    return corretto; 
}

void printArray (int *array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " "; 
    }
    cout << endl; 
}