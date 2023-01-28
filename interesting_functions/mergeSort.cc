#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


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


void mergeSort_vec (vector<int> &vec, int first, int last) {
    
    int mid = (last + first) / 2;
    if (first < last) {
        mergeSort_vec (vec,first,mid);
        mergeSort_vec (vec,mid+1,last);
        merge_vec (vec,first,mid,last);
    }

}

void merge_vec (vector <int> &vec, int first, int mid, int last) {

    vector <int> b;
    int i = first, j = mid+1, index = first;
    while ((i <= mid) || (j <= last)) {
        if ((i <= mid) && (j <= last)) {
            if (vec[i]<=vec[j]) {
                b.push_back(vec[i]);
                ++i;
            }
            else {
                b.push_back(vec[j]);
                ++j;
            }
        }
        if ((i > mid) && (j <= last)) {
            b.push_back(vec[j]);
            ++j;
        }

        if ((j > last) && (i <= mid)) {
            b.push_back(vec[i]);
            ++i;
        }
    }
    
    for (int i : b) {
        vec[index] = i;
        ++index;
    }
}