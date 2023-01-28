#include <iostream>
#include <vector>


using namespace std;

void mergeSort (vector<int> &vec, int first, int last);
void merge (vector <int> &vec, int first, int mid, int last);
bool conta (vector<int> a, int n);

int main () {

    vector <int> a;
    int n = 5;
    a.resize(n);
    a[0] = 3;
    a[2] = 3;
    a[1] = 1;
    a[4] = 1;
    //a[3] = 4;
    a[3] = 3;
    //a[5] = 4;
    //a[6] = 5;
    mergeSort(a,0,n-1);
    for (int t : a) {
        cout << t << " ";
    }
    cout << "Appaiono dei numeri lo stesso numero di volte? " << (conta(a,n) ? "Si" : "No") << endl;

    return 0;
}

void mergeSort (vector<int> &vec, int first, int last) {
    
    int mid = (last + first) / 2;
    if (first < last) {
        mergeSort (vec,first,mid);
        mergeSort (vec,mid+1,last);
        merge (vec,first,mid,last);
    }

}

void merge (vector <int> &vec, int first, int mid, int last) {

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

bool conta (vector<int> a, int n) {

    vector<int> heldCount;
    int index = a[0]; /*ovviamente il caso in cui il vettore è vuoto è da saltare*/
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == index) {
            ++count;
        }
        else if (a[i] != index) {
            heldCount.push_back(count);
            index = a[i];
            count = 1;
        }
    }
    mergeSort(heldCount,0,heldCount.size()-1);
    int start = heldCount[0];
    for (int j = 1; j < heldCount.size(); j++) {
        if (heldCount[j] == start)
            return true;
        else
            start = heldCount[j];
    }

    return false;
}

/*Faccio un mergeSort = theta(nlogn), nel conta faccio un altro mergeSort e due cicli di costo computazionale di O(n), quindi prendendo la funzione di costo computazionale maggiore nella nostra funzione si può dimostrare che l'algoritmo prodotto ha una complessità nlogn */