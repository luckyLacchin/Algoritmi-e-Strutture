#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void mergeSort (vector<int> &vec, int first, int last);
void merge (vector <int> &vec, int first, int mid, int last);

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");
    vector <int> vec;
    int dim = 0, temp;
    in >> dim;
    while (in >> temp) {
        vec.push_back(temp);
    }
    mergeSort(vec,0,dim-1); 
    for (int t : vec) {
        out << t << " ";
    }
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